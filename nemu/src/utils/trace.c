#include <common.h>
#include <utils.h>

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

void mtracePrint(paddr_t addr,word_t data,bool w_r){
  if(w_r == 0)
    printf("load  %08x : %08x\n",addr,data);
  else
    printf("store %08x : %08x\n",addr,data);
}

