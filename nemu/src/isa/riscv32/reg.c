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

#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  for(int i = 0;i < 8; i++){
    for(int j = 0;j < 4; j++){
      printf("%s = 0x%08x",regs[i*4+j],cpu.gpr[i*4+j]);
      if(j == 3)
        printf("\n");
      else
        printf(", ");
    }
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  int reg_pos = 0;
  if(!strcmp(regs[0],s))
    return 0;
  if(!strcmp("$pc",s))
    return cpu.pc;
  s++; // cut the char '$'
  for(;reg_pos < 32;reg_pos ++){
    if(!strcmp(regs[reg_pos],s))
      break;
  }
  if(reg_pos >= 32) {
    *success = false;
    Log("Wrong reg");
    assert(0);
  }
  return cpu.gpr[reg_pos];
}
