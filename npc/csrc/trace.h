#include "common.h"

int parse_args(int argc, char *argv[]);
void ringIn(char* str);
void ringPrint();
void mtracePrint(uint32_t addr,uint32_t data,bool w_r);
void init_elf(const char* elf_file);
extern "C" void ftraceCall(uint32_t addr,uint32_t pc);
extern "C" void ftraceRet(uint32_t addr,uint32_t pc);