/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

word_t expr(char *e, bool *success,char* end);
int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
//ramdon test

  // FILE* fp = fopen("tools/gen-expr/input","r");
  // if(fp == NULL)
  //   Log("NULL");
  // char buf[65536] = {0};
  // char ans[1000] = {0};
  // char exp[65536] = {0};
  // while(fgets(buf,sizeof(buf),fp)){
  //   memset(ans,0,sizeof(ans));
  //   memset(exp,0,sizeof(exp));
  //   sscanf(buf,"%s",ans);
  //   strcpy(exp,buf+strlen(ans));
  //   exp[strcspn(exp,"\n")] = 0;
  //   printf("ans is %s exp is %s\n",ans,exp);
  //   uint32_t x = atoi(ans);
  //   bool b;
  //   uint32_t a = expr(exp,&b,exp+strlen(exp));
  //   if(a != x)
  //     assert(0);
  // }
  //

  /* Start engine. */
  engine_start();
  return is_exit_status_bad();
  return 0;
}
