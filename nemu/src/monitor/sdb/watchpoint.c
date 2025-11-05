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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char *str;
  uint32_t val;
  bool state;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
  if(free_ == NULL)
    assert(0);
  WP *l = NULL,*r = free_;
  while(r -> next != NULL){
    l = r;
    r = r -> next;
  }
  r -> next = head;
  head = r;
  r -> state = true;
  if(l != NULL)
    l -> next = NULL;
  else
    free_ = NULL;
  return r;
}

void free_wp(WP *wp){
  if(wp->state == false){
    printf("This wp not in use\n");
    return;
  }
  WP *temp = head,*l = NULL;
  while(temp != wp){
    l = temp;
    temp = temp -> next;
  }
  if(l == NULL)
    head = head->next;
  else
    l -> next = temp->next;
  wp -> next = free_;
  free_ = wp;
  wp -> state = false;
  free(wp->str);
}

void watch(){
  WP* h = head;
  bool success = true;
  while(h != NULL){
    uint32_t val = expr(h->str,&success,h->str+strlen(h->str));
    if(val != h->val){
      nemu_state.state = NEMU_STOP;
      Log("Watchpoint No%d (%s) changed : %x -> %x",h->NO,h->str,h->val,val);
      h->val = val;
    }
    h = h->next;
  }
  return;
}

void print_wp(){
  WP* h = head;
  while(h != NULL){
    printf("No %d (%s) val %x \n",h->NO,h->str,h->val);
    h = h->next;
  }
  return;
}

void delete_wp(int n){
  free_wp(&wp_pool[n]);
  wp_pool[n].str = 0;
  wp_pool[n].val = 0;
  return;
}






