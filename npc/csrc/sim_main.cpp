#include <verilated.h>
#include <sys/time.h>
#include "verilated_fst_c.h"

// Include model header, generated from Verilating "top.v"
#include "VTop.h"
#include <stdint.h>
#include <stdio.h>

void npc_quit(){
  Verilated::gotFinish(true);
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
  // printf("0x%08x 0x%08x\n",addr,*(uint32_t *)addr);
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
  if(addr == RTC_ADDR || addr == RTC_ADDR+4){
    return (addr == RTC_ADDR) ? (uint32_t)(us & 0xFFFFFFFF) : (uint32_t)(us >> 32);
  }
  uint32_t ret = host_read(guest_to_host(addr & ~0x3));
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
    wen = 0;
    host_write(guest_to_host(addr),bitc, data);
  }
}

extern "C" void ebreak(int exit_code){
  static int flag = 0;
  if(!flag){
    flag = 1;
    if(!exit_code)
      printf("\033[1;32mNPC HIT GOOD TRAP\033[0m\n");
    else
      printf("\033[1;31mNPC HIT BAD TRAP\033[0m\n");
  }
  npc_quit();
}

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};


static uint32_t g_gpr[32];
static bool regPrint = 1;
extern "C" void regRead(uint32_t gpr[32]){
  for(int i = 0;i < 8;i ++){
    for(int j = 0;j < 4;j ++){
      g_gpr[i*4+j] = gpr[i*4+j];
      if(regPrint)
        printf("%s = 0x%08x ",regs[i*4+j],gpr[i*4+j]);
    }
    if(regPrint)
      printf("\n");
  }
}



VTop* top;
VerilatedContext* contextp;
bool npcState = true;

void isa_reg_display(){
  top->io_regValid = 1;
  top->eval();
  top->io_regValid = 0;
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
  // while(1){
  //   us = get_time();
  //   top->clock = 0;
  //   top->eval();
  //   top->clock = 1;
  //   top->eval();
  // }
  for(;n > 0;n --){
    if(contextp->gotFinish()) {return true;}
    wen = 1;
    us = get_time();
    top->clock = 0;
    top->eval();
    top->clock = 1;
    top->eval();
    // tfp->dump(main_time);
    // main_time++;
  }
  return 0;
}

void init_sdb();
void sdb_mainloop();

int main(int argc, char** argv) {
  // See a similar example walkthrough in the verilator manpage.

  // This is intended to be a minimal example.  Before copying this to start a
  // real project, it is better to start with a more complete example,
  // e.g. examples/c_tracing.

  // Construct a VerilatedContext to hold simulation time, etc.
  contextp = new VerilatedContext;

  // Pass arguments so Verilated code can see them, e.g. $value$plusargs
  // This needs to be called before you create any model
  contextp->commandArgs(argc, argv);

  // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
  top = new VTop{contextp};
  
  Verilated::traceEverOn(true);
  VerilatedFstC* tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open("wave.fst");
  uint64_t main_time = 0;
  init_mem();
  uint32_t *M = (uint32_t *)pmem;
  
  FILE * fp = fopen("/home/parano1d/ysyx-workbench/npc/obj_dir/test.bin","rb");
  uint64_t count = 0;
  uint32_t temp = 0;
  size_t n;
  M += 0x00000000;
  while((n = fread(&temp,1,sizeof(uint32_t),fp)) > 0) {
  // printf("0x%08x : 0x%08x\n",M+count,temp);
      M[count] = temp;
      count+=1;
  }
  // Simulate until $finish
  for(int i = 0;i < 1 ;i ++){
    top->reset = 1;
    top->clock = 0;
    top->eval();
    top->clock = 1;
    top->eval();
    top->reset = 0;
  }

  // while(1){
  //   wen = 1;
  //   us = get_time();
  //   top->clock = 0;
  //   top->eval();
  //   top->clock = 1;
  //   top->eval();
  // }
  init_sdb();
  sdb_mainloop();
  //top->io_inst = pmem_read(top->io_pc , 4);
  //printf("pc: %x 0x%08x\n",top->io_pc,top->io_inst);
  // Evaluate model

  // Final model cleanup
  top->final();
  tfp->close();

  // Destroy model
  delete top;

  // Return good completion status
  return 0;
}

