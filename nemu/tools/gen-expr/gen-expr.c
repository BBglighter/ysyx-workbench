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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int pos = 0;
static bool space = false;
uint32_t choose(uint32_t n){
  int r = rand();
  space = r % 2;
  return r % n;
}

void gen_num(){
  uint32_t num = rand() % 1000;
  space = num % 2;
  if(space) buf[pos++] = ' ';
  char temp[6];
  int k = 0;
  if(num == 0) buf[pos++] = '0';
  while(num){
    temp[k++] = num%10 + '0';
    num = num / 10;
  }
  k--;
  for(;k >= 0;k --){
    buf[pos++] = temp[k]; 
  }
  return;
}

void gen_rand_op(){
  space = rand() % 2;
  if(space) buf[pos++] = ' ';
  switch(choose(4)){
    case 0: buf[pos++] = '+'; break;
    case 1: buf[pos++] = '-'; break;
    case 2: buf[pos++] = '*'; break;
    default:buf[pos++] = '/';
  }
  return;
}

void gen_brakets(int n){
  space = rand() % 2;
  if(space) buf[pos++] = ' ';
  buf[pos++] = n;
}

static void gen_rand_expr() {
  if(pos < 65536){
    switch(choose(3)){
      case 0: gen_num(); break;
      case 1: gen_brakets('('); gen_rand_expr(); gen_brakets(')'); break;
      default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
    }
  }else{
    printf("overflow");
    memset(buf,0,63356);
  }
  buf[pos] = '\0';
  return;
}

int main(int argc, char *argv[]){ 
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    pos = 0;
    memset(buf,0,63356);
    gen_rand_expr();
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -Wall -Werror -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
