#include "common.h"
#include "util.h"
#include <elf.h>
#include <getopt.h>

char *elf_file = NULL;
char *diff_so_file = NULL;
int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"ftrace"   , required_argument, NULL, 'f'},
    // {"diff"     , required_argument, NULL, 'd'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:f:", table, NULL)) != -1) {
    switch (o) {
      case 'f': elf_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      // case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

#define iringbufMax 20
char ringbuffer[iringbufMax][128];
int pos = 0;
int front = 0;
int size = 0;
void ringIn(char* str){
  strncpy(ringbuffer[pos],str,strlen(str)+1);
  if(size == 20){
    front = (front+1)%iringbufMax;
  }else{
    size++;
  }
  pos = (pos+1)%iringbufMax;
}

void ringPrint(){
  puts(ANSI_FMT("INST BEFORE ERROR", ANSI_FG_YELLOW));
  for(int i = 0;i < size;i ++){
    puts(ringbuffer[(front+i)%iringbufMax]);
  }
}

void mtracePrint(uint32_t addr,uint32_t data,bool w_r){
  if(w_r == 0)
    printf("load  %08x : %08x\n",addr,data);
  else
    printf("store %08x : %08x\n",addr,data);
}

struct faddr2name{
  uint32_t no;
  char name[100];
  uint32_t addr;
  uint32_t len;
};
struct faddr2name *f_a2n[100];
static int fsize;

void init_elf(const char* elf_file){
  FILE *elf_fp = fopen(elf_file,"rb");
  assert(elf_fp);
  Elf32_Ehdr eh;
  assert(fread(&eh, 1, sizeof(Elf32_Ehdr), elf_fp));
  fseek(elf_fp, eh.e_shoff, SEEK_SET);
  Elf32_Shdr *sh = (Elf32_Shdr *)malloc(sizeof(Elf32_Shdr)*eh.e_shnum);
  for(int i = 0;i < eh.e_shnum;i ++){
    assert(fread(&sh[i], 1, sizeof(Elf32_Shdr), elf_fp));
  }
  for(int i = 0;i < eh.e_shnum;i ++){
    if(sh[i].sh_type == SHT_SYMTAB){
      int strtab_idx = sh[i].sh_link;
      char *strtab = (char *)malloc(sizeof(char) * sh[strtab_idx].sh_size);
      fseek(elf_fp, sh[strtab_idx].sh_offset, SEEK_SET);
      assert(fread(strtab,1,sh[strtab_idx].sh_size,elf_fp));
      int num_sym = sh[i].sh_size / sh[i].sh_entsize;
      fseek(elf_fp, sh[i].sh_offset, SEEK_SET);
      for(int i = 0;i < num_sym;i ++){
        Elf32_Sym sym;
        assert(fread(&sym, 1, sizeof(sym), elf_fp));
        if((sym.st_info & 0xF) == STT_FUNC){
          f_a2n[fsize] = (faddr2name *)malloc(sizeof(struct faddr2name));
          f_a2n[fsize]->no = fsize;
          f_a2n[fsize]->addr = sym.st_value;
          f_a2n[fsize]->len  = sym.st_size;
          strcpy(f_a2n[fsize]->name,strtab+sym.st_name);
          fsize++;
        }
      }
      free(strtab);
    }
  }
  free(sh);
  fclose(elf_fp);
}


static int lastfun = -1;
static int funCount = 0;

extern "C" void ftraceCall(uint32_t addr,uint32_t pc){
  for(int i = 0;i < fsize;i ++){
    if(addr >= f_a2n[i]->addr && addr <= f_a2n[i]->addr+f_a2n[i]->len && (i != lastfun)){
      lastfun = i;
      printf("0x%08x: ",pc);
      for(int i = 0;i < funCount;i ++)
        printf(" ");
      printf("call [%s @0x%08x]\n",f_a2n[i]->name,addr);
      funCount++;
      return;
    }
  }
}
extern "C" void ftraceRet(uint32_t addr,uint32_t pc){
  for(int i = 0;i < fsize;i ++){
    if(addr >= f_a2n[i]->addr && addr <= f_a2n[i]->addr+f_a2n[i]->len && (i != lastfun)){
      funCount--;
      printf("0x%08x: ",pc);
      for(int i = 0;i < funCount;i ++)
        printf(" ");
      printf("ret %s\n",f_a2n[i]->name);
      lastfun = i;
      return;
    }
  }
}


// static const char* lastdevice;
// void dtrace(const char *name,uint32_t addr){
//   if(name != lastdevice){
//     printf("device : %s @0x%08x\n",name,addr);
//     lastdevice = name;
//   }
// }











