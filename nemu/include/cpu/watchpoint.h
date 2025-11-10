#include <common.h>

//#ifdef CONFIG_WATCHPOINT
#define NR_WP  32
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char *str;
  uint32_t val;
  bool state;
} WP;


WP* new_wp();
WP* free_wp();
void watch();
void print_wp();
void delete_wp();
//#endif
