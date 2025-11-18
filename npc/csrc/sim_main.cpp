#include <verilated.h>
#include "verilated_fst_c.h"

// Include model header, generated from Verilating "top.v"
#include "VTop.h"
#include <stdint.h>
#include <stdio.h>

static uint8_t *pmem = NULL;
void init_mem() {
  pmem = (uint8_t *)malloc(sizeof(uint32_t) * 0x80000000);
  assert(pmem);
}

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: printf("0x%08x \n",*(uint32_t *)addr); return *(uint32_t *)addr;
  }
}

static inline void host_write(void *addr, int len, int data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: printf("0x%08x \n",*(uint32_t *)addr); *(uint32_t *)addr = data; return;
  }
}

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr; }

extern "C" int pmem_read(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

extern "C" void pmem_write(int addr, int len, int data) {
  host_write(guest_to_host(addr), len, data);
}

extern "C" void ebreak(int exit_code){
  static int flag = 0;
  if(!flag){
    flag = 1;
    printf("npc return %d\n",exit_code);
  }
  Verilated::gotFinish(true);
}

int main(int argc, char** argv) {
    // See a similar example walkthrough in the verilator manpage.

    // This is intended to be a minimal example.  Before copying this to start a
    // real project, it is better to start with a more complete example,
    // e.g. examples/c_tracing.

    // Construct a VerilatedContext to hold simulation time, etc.
    VerilatedContext* contextp = new VerilatedContext;

    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    contextp->commandArgs(argc, argv);

    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    VTop* top = new VTop{contextp};
    
    Verilated::traceEverOn(true);
    VerilatedFstC* tfp = new VerilatedFstC;
    top->trace(tfp, 99);
    tfp->open("wave.fst");
    uint64_t main_time = 0;
    init_mem();
    uint32_t *M = (uint32_t *)pmem;
    
    FILE * fp = fopen("/home/parano1d/ysyx-workbench/npc/obj_dir/sum.bin","rb");
    uint64_t count = 0;
    uint32_t temp = 0;
    size_t n;

    while((n = fread(&temp,1,sizeof(uint32_t),fp)) > 0) {
        M[count] = temp;
        count+=1;
    }
    
    // Simulate until $finish
    while (!contextp->gotFinish()) {

        top->io_inst = pmem_read(top->io_pc , 4);
        printf("pc: %x 0x%08x\n",top->io_pc,top->io_inst);
        // Evaluate model
        top->clock = 0;
        top->eval();
        top->clock = 1;
        top->eval();
        tfp->dump(main_time);
        main_time++;
    }

    // Final model cleanup
    top->final();
    tfp->close();

    // Destroy model
    delete top;

    // Return good completion status
    return 0;
}

