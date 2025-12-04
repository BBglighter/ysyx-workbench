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

#define mstatus 0x300
#define mtvec 0x305
#define mepc 0x341
#define mcause 0x342

static word_t csr[4096] = {
  [0x300] = 0x1800,
};


word_t isa_csr_w(word_t NO,word_t data){
  word_t t = csr[NO];
  csr[NO] = data;
  return t;
}

word_t csr_read(word_t NO){
  return csr[NO];
}

void csr_write(word_t NO,word_t data){
  csr[NO] = data;
}

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  csr[0x341] = epc;
  csr[0x342] = NO;
  return csr[0x305];
}


word_t isa_query_intr() {
  return INTR_EMPTY;
}
