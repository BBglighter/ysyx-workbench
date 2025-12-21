#include <verilated.h>
#include <sys/time.h>
#include "verilated_fst_c.h"

// Include model header, generated from Verilating "top.v"
#include "VTop.h"
#include "common.h"
#include "trace.h"
#include "util.h"
#include "difftest.h"

// #define FST
// #define TRACE
// #define MTRACE
// #define FTRACE
// #define DIFFTEST

VTop* top;
VerilatedContext* contextp;
VerilatedFstC* tfp; 
bool npcState = true;

static uint64_t runtime;
static uint64_t main_time = 0;

void npc_quit(){
  #ifdef FST
    tfp->dump(main_time);
    main_time++;
  #endif
  Verilated::gotFinish(true);
  top->final();
  tfp->close();
  printf("npc end with %ld period\n",runtime);
}

static uint8_t *pmem = NULL;
void init_mem() {
  pmem = (uint8_t *)malloc(sizeof(uint32_t) * 0xFFFFFFFF);
  assert(pmem);
}

static inline uint32_t host_read(void *addr) {
  // printf("0x%08x 0x%08x\n",addr,*(uint32_t *)addr);
  if(addr >= pmem){
  return *(uint32_t *)addr;
  }else{
    return 0;
  }
}

static inline void host_write(void *addr, int len, int data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
  }
}

static uint8_t count = 0;
uint8_t* guest_to_host(uint32_t paddr) {
  // printf("%x \n",paddr);
  if( paddr == 0 ){
    count++;
    return &count;
  }else{
    // printf("0x%08x \n",pmem + paddr - 0x80000000);
    return pmem + paddr - 0x80000000;
  }
}


static uint64_t get_time_internal() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
  uint64_t us = now.tv_sec * 1000000 + now.tv_nsec / 1000;
  // struct timeval now;
  // gettimeofday(&now, NULL);
  // uint64_t us = now.tv_sec * 1000000;
  return us;
}

static uint64_t boot_time = 0;
uint64_t get_time() {
  if (boot_time == 0) boot_time = get_time_internal();
  uint64_t now = get_time_internal();
  return now - boot_time;
}

#define RTC_ADDR 0x10000008
static uint64_t us = get_time();
extern "C" int pmem_read(uint32_t addr) {
  uint32_t ret;
  static uint32_t lastaddr = 0,lastdata = 0;
  if(addr == RTC_ADDR || addr == RTC_ADDR+4){
    ret = (addr == RTC_ADDR) ? (uint32_t)(us & 0xFFFFFFFF) : (uint32_t)(us >> 32);
  }else{
    ret = host_read(guest_to_host(addr & ~0x3));
  }
  // printf("0x%08x 0x%08x\n",addr,ret);
  #ifdef MTRACE
  if((addr != lastaddr || ret != lastdata) && addr != 0){
    mtracePrint(addr,ret,0);
    lastaddr = addr;
    lastdata = ret;
  }
  #endif
  return ret;
}

static int wen = 1;
extern "C" void pmem_write(int addr, int wmask, int data) {
  if(addr == 0x10000000){
    putchar(data);
    return;
  }
  int bitc = 0;
  while(wmask){
    if(wmask&1 != 0)
      bitc++;
      wmask = wmask >> 1;
    }
  if(wen){
    #ifdef MTRACE
    mtracePrint(addr,data,1);
    #endif
    wen = 0;
    // printf("0x%08x 0x%08x\n",addr,data);
    host_write(guest_to_host(addr),bitc, data);
  }
}

extern "C" void ebreak(int exit_code){
  static int flag = 0;
  if(!flag){
    flag = 1;
    if(!exit_code)
      printf("\033[1;32mNPC HIT GOOD TRAP\033[0m\n");
    else{
      printf("\033[1;31mNPC HIT BAD TRAP\033[0m\n");
    }
  }
  npc_quit();
  assert(!exit_code);
}
static char logbuf[128];
static char difftestbuf[128]; //locate the last inst
static uint32_t lastpc;
char enter = '\n';
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

FILE *fp = NULL;


extern "C" void itrace(uint32_t pc,uint32_t instr){
  #ifdef TRACE
  strcpy(difftestbuf,logbuf);
  memset(logbuf,0,128);
  if(pc == lastpc) return;
  lastpc = pc;
  char *p = logbuf;
  p += snprintf(p, sizeof(logbuf),"0x%08x:",pc);
  uint8_t *inst = (uint8_t*)&instr;
  for(int i = 0;i < 4;i ++){
    p += snprintf(p, 4, " %02x",inst[i]);
  }
  int space_len = 1;
  memset(p, ' ', space_len);
  p += space_len;
  disassemble(p, logbuf + sizeof(logbuf) - p, pc, (uint8_t *)&instr, 4);
  fwrite(logbuf,1,strlen(logbuf),fp);
  ringIn(logbuf);
  #endif
}


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};


uint32_t g_gpr[32];
static bool regPrint = 1;
extern "C" void regRead(uint32_t gpr[32],uint32_t pc){
  if(regPrint)printf("pc = 0x%08x\n",pc);
  for(int i = 0;i < 8;i ++){
    for(int j = 0;j < 4;j ++){
      g_gpr[i*4+j] = gpr[i*4+j];
      if(regPrint)
        printf("%s = 0x%08x ",regs[i*4+j],gpr[i*4+j]);
    }
    if(regPrint){
      printf("\n");
    }
  }
}

void isa_reg_display(){
  top->io_regValid = 1;
  top->eval();
  top->io_regValid = 0;
}

bool isa_difftest_checkregs(uint32_t *ref){
  regPrint = 0;
  isa_reg_display();
  regPrint = 1;
  for(int i = 0;i < 32;i ++){
    if(ref[i] != g_gpr[i]){
      printf("wrong inst : %s",difftestbuf);
      printf(ANSI_FMT("npc_gpr[%d] (%08x) != nemu_gpr[%d] (%08x) \n", ANSI_FG_RED),i,g_gpr[i],i,ref[i]);
      return false;
    }
  }
  return true;
}




uint32_t isa_reg_str2val(char* str){
  regPrint = 0;
  isa_reg_display();
  regPrint = 1;
  str++;
  for(int i = 0;i < 32;i ++){
    if(!strcmp(str,regs[i]))
      return g_gpr[i];
  }
  return 0;
}

bool npc_exec(uint64_t n){
  for(;n > 0;n --){
    if(contextp->gotFinish()) {return true;}
    wen = 1;
    us = get_time();
    top->clock = 0;
    top->eval();
    top->clock = 1;
    top->eval();
    runtime++;
    #ifdef FST
      tfp->dump(main_time);
      main_time++;
    #endif
    
    #ifdef DIFFTEST
    if(top->io_difftest)
      difftest_step();
    #endif
  }
  return 0;
}

void init_sdb();
void sdb_mainloop();
void init_disasm(); 

extern char* elf_file;
int main(int argc, char** argv) {
  setvbuf(stdout, NULL, _IONBF, 0);
  parse_args(argc,argv);

  #ifdef FTRACE
  init_elf(elf_file);
  #endif
  
  #ifdef TRACE
  init_disasm();
  fp = fopen("npc-log.txt","w");
  #endif
  
  // Construct a VerilatedContext to hold simulation time, etc.
  contextp = new VerilatedContext;

  // This needs to be called before you create any model
  contextp->commandArgs(argc, argv);

  // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
  top = new VTop{contextp};
  
  Verilated::traceEverOn(true);
  tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open("wave.fst");
  init_mem();
  uint8_t *M = (uint8_t *)pmem;
  
  FILE * fp = fopen("/home/parano1d/ysyx-workbench/npc/test.bin","rb");
  uint64_t count = 0;
  uint32_t temp = 0;
  size_t n;
  M += 0x00000000;
  while((n = fread(&temp,1,sizeof(uint8_t),fp)) > 0) {
  // printf("0x%08x : 0x%08xn",M+count,temp);
      M[count] = temp;
      count+=1;
  }

  //init difftest
  static int difftest_port = 1234;
  
  #ifdef DIFFTEST
  init_difftest(count,difftest_port);
  #endif

  // Simulate until $finish
  for(int i = 0;i < 1 ;i ++){
    top->reset = 1;
    top->clock = 0;
    top->eval();
    top->clock = 1;
    top->eval();
    top->reset = 0;
    #ifdef FST
      tfp->dump(main_time);
      main_time++;
    #endif
  }

  init_sdb();
  sdb_mainloop();

  // Final model cleanup

  // Destroy model
  delete top;

  // Return good completion status
  return 0;
}

