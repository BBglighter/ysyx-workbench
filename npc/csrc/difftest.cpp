#include <dlfcn.h>
#include "common.h"

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

extern "C" void ebreak(int exit_code);
void isa_reg_display() ;
bool isa_difftest_checkregs(uint32_t *ref);
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };
#define RESET_VECTOR 0x80000000

extern uint32_t g_gpr[32];
uint8_t* guest_to_host(uint32_t paddr);
extern "C" {

void init_difftest(long img_size, int port) {

  void *handle;
  handle = dlopen("/home/parano1d/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so", RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  // ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
  // assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(g_gpr, DIFFTEST_TO_REF);
}

static void checkregs(uint32_t *ref){
  if(!isa_difftest_checkregs(ref)) {
    isa_reg_display();
    ebreak(1);
  }
}

void difftest_step(){
  uint32_t ref_r[32];
  ref_difftest_exec(1);
  ref_difftest_regcpy(ref_r, DIFFTEST_TO_DUT);
  checkregs(ref_r);
}

}
