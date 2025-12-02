#include <common.h>
#include <utils.h>
#include <elf.h>

#define iringbufMax 20
char ringbuffer[iringbufMax][128];
int pos = 0;
int front = 0;
int size = 0;
void ringIn(char* str){
  // strncpy(ringbuffer[pos],str,strlen(str)+1);
  snprintf(ringbuffer[pos], 128, "%s", str);
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

void mtracePrint(paddr_t addr,word_t data,bool w_r){
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
  Assert(elf_fp, "Can not open '%s'", elf_file);
  Elf32_Ehdr eh;
  Assert(fread(&eh, 1, sizeof(Elf32_Ehdr), elf_fp),"wrong elf");
  fseek(elf_fp, eh.e_shoff, SEEK_SET);
  Elf32_Shdr *sh = malloc(sizeof(Elf32_Shdr)*eh.e_shnum);
  for(int i = 0;i < eh.e_shnum;i ++){
    Assert(fread(&sh[i], 1, sizeof(Elf32_Shdr), elf_fp),"wrong elf");
  }
  for(int i = 0;i < eh.e_shnum;i ++){
    if(sh[i].sh_type == SHT_SYMTAB){
      int strtab_idx = sh[i].sh_link;
      char *strtab = malloc(sizeof(char) * sh[strtab_idx].sh_size);
      fseek(elf_fp, sh[strtab_idx].sh_offset, SEEK_SET);
      Assert(fread(strtab,1,sh[strtab_idx].sh_size,elf_fp),"wrong elf");
      int num_sym = sh[i].sh_size / sh[i].sh_entsize;
      fseek(elf_fp, sh[i].sh_offset, SEEK_SET);
      for(int i = 0;i < num_sym;i ++){
        Elf32_Sym sym;
        Assert(fread(&sym, 1, sizeof(sym), elf_fp),"wrong elf");
        if((sym.st_info & 0xF) == STT_FUNC){
          f_a2n[fsize] = malloc(sizeof(struct faddr2name));
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

void ftraceCall(uint32_t addr,uint32_t pc){
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
void ftraceRet(uint32_t addr,uint32_t pc){
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


static const char* lastdevice;
void dtrace(const char *name,uint32_t addr){
  if(name != lastdevice){
    printf("device : %s @0x%08x\n",name,addr);
    lastdevice = name;
  }
}











