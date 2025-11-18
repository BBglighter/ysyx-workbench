#include <verilated.h>
#include "verilated_vcd_c.h"

// Include model header, generated from Verilating "top.v"
#include "VTop.h"
#include <stdint.h>
#include <stdio.h>

static uint8_t *pmem = NULL;
void init_mem() {
  pmem = (uint8_t *)malloc(sizeof(uint32_t) * 100);
  assert(pmem);
}

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0);
  }
}

static inline void host_write(void *addr, int len, int data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
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
  printf("npc return %d\n",exit_code);
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
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("wave.vcd");
    uint64_t main_time = 0;

    init_mem();
    uint32_t *byte4 = (uint32_t *)pmem;
    byte4[0] = 0x00500093;
    byte4[1] = 0x00308113;
    byte4[2] = 0xfff10193;
    byte4[3] = 0xfff10193;
    byte4[4] = 0x00100073;
    // Simulate until $finish
    int n = 10;
    while (!contextp->gotFinish() && n--) {

        top->io_inst = pmem_read(top->io_pc , 4);
        printf("pc: %x 0x08%x\n",top->io_pc,top->io_inst);
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

