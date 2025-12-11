#include <am.h>
#include <klib-macros.h>
#include <klib.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))
Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }
#define SERIAL_PORT 0x10000000
void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  npc_trap(code);
  while (1);
}

void read_csr() {
  unsigned long mvendorid;
  unsigned long marchid;

  asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
    
  asm volatile("csrr %0, marchid" : "=r"(marchid));
    
  for(int i = 0;i < 4;i ++){
    char c = mvendorid >> (24 - i*8);
    printf("%c",c);
  }
    printf("_%d\n", marchid);
}

void _trm_init() {
  //read_csr();
  int ret = main(mainargs);
  halt(ret);
}
