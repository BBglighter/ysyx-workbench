#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdint.h>

bool npc_exec(uint64_t n);
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

#define NR_CMD 2

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


static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  // { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the  program", cmd_c },
  { "si","step in the program", cmd_si},
  // { "info","show info u choose",cmd_info},
  // { "x","show memory",cmd_x},
};

void sdb_mainloop() {
  for (char *str; (str = rl_gets()) != NULL; ) {
    //char *
    char *str_end = str + strlen(str);
    
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
