#include <am.h>
#include <klib-macros.h>
#include <klib.h>


extern char _heap_start;
int main(const char *args);
extern char _pmem_start;
extern char _data_addr; 
extern char _data_len; 
extern char _data_loadaddr; 
extern char _bss_start;
extern char _bss_end;
#define PMEM_SIZE (4 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))
Area heap = RANGE(&_heap_start, &_heap_start + 4*1024);
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

void _trm_init() {
  memcpy((void*)&_data_addr,(void*)&_data_loadaddr,(size_t)&_data_len);
  memset((void*)&_bss_start, 0, (void*)&_bss_end - (void*)&_bss_start);
  int ret = main(mainargs);
  halt(ret);
}
