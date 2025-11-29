#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdint.h>


void init_regex();
bool npc_exec(uint64_t n);
void isa_reg_display();
static bool npcState;

static char* rl_gets() {
  if(npcState) {return NULL;}
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

#define NR_CMD 4

static int cmd_c(char *args) {
  npcState = npc_exec(-1);
  return 0;
}

static int cmd_si(char *args) {
  char *num_c = strtok(args," ");
  int n = 0;
  n = atoi(num_c);
  npcState = npc_exec(n);
  return 0;
}

static int cmd_info(char *args){
  char* arg = strtok(args," ");
  if(*arg == 'r')
    isa_reg_display();
  else if(*arg == 'w')
    printf("TODO\n");
  else
    printf("wrong args\n");
  
  return 0;
}

static char* str_end = 0;


extern "C" int pmem_read(uint32_t addr);
uint32_t expr(char *e,bool *success,char *end);

static int cmd_x(char *args){
  char* arg = strtok(args," ");
  int n = 0;
  for(int i = 0;i < strlen(arg);i++){
    if(arg[i] >= '0' && arg[i] <= '9')
      n = n*10 + arg[i]-'0';
    else
      printf("input wrong\n");
  }
  arg = strtok(NULL," ");
  // int l = 0; uint32_t addr = 0,temp = 0; 
  // while(l < strlen(arg)){
  //   for(int i = 0;i < 2;i++,l++){
  //     temp = (i == 1)?(temp << 4):0;
  //     if(arg[l] >= '0' && arg[l] <= '9')
  //       temp += arg[l] - '0';
  //     else if(arg[l] >= 'a' && arg[l] <= 'f')
  //       temp += arg[l]+9 - 'a';
  //     else if(arg[l] >= 'A' && arg[l] <= 'F')
  //       temp += arg[l]+9 - 'A';
  //   }
  //   addr = addr << 8;
  //   addr += temp;
  // }
  //
  bool success = true;
  uint32_t addr = expr(arg,&success,str_end);

  for(int i = 0;i < n;i++){
    uint32_t value = pmem_read(addr+4*i);
    printf("0x%08x : 0x%08x\n",addr+4*i,value);
  }
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  // { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the  program", cmd_c },
  { "si","step in the program", cmd_si},
  { "info","show info u choose",cmd_info},
  { "x","show memory",cmd_x}
};

void sdb_mainloop() {
  for (char *str; (str = rl_gets()) != NULL; ) {
    //char *
    str_end = str + strlen(str);
    
    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }
    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_regex();
void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

}

