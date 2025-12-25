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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>
#include <utils.h>

// #define DIFFTEST_REF
#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

static uint8_t mrom[4096];
static uint8_t sram[4096];

uint8_t* guest_to_host(paddr_t paddr) {
  #ifdef DIFFTEST_REF
    return &mrom[0];
  #endif
  return pmem + paddr - CONFIG_MBASE; 
}
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }



void mtracePrint(paddr_t addr,word_t data,bool w_r);


static word_t sram_read(paddr_t addr, int len) {
  word_t ret = host_read((sram + addr - 0x0f000000), len);
  IFDEF(CONFIG_MTRACE,mtracePrint(addr,ret,0));
  return ret;
}

static word_t mrom_read(paddr_t addr, int len) {
  word_t ret = host_read((mrom + addr - 0x20000000), len);
  IFDEF(CONFIG_MTRACE,mtracePrint(addr,ret,0));
  return ret;
}

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  IFDEF(CONFIG_MTRACE,mtracePrint(addr,ret,0));
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
  IFDEF(CONFIG_MTRACE,mtracePrint(addr,data,1));
}

static void sram_write(paddr_t addr, int len, word_t data) {
  host_write((sram + addr - 0x0f000000), len, data);
  IFDEF(CONFIG_MTRACE,mtracePrint(addr,data,1));
}

static void mrom_write(paddr_t addr, int len, word_t data) {
  host_write((mrom + addr - 0x20000000), len, data);
  IFDEF(CONFIG_MTRACE,mtracePrint(addr,data,1));
}

static void out_of_bound(paddr_t addr) {
  #ifdef DIFFTEST_REF
    return;
  #endif
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

#define RTC_ADDR 0x10000008
word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  if (likely(in_mrom(addr))) return mrom_read(addr, len);
  if (likely(in_sram(addr))) return sram_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  // if(addr == RTC_ADDR || addr == RTC_ADDR+4){
  //   printf("test\n");
  //   return mmio_read(addr, len);
  // }
  // #ifdef DIFFTEST_REF
  // if(addr == RTC_ADDR || addr == RTC_ADDR+4){
  //   us = get_time();
  //   printf("%lx\n",us);
  //   return (addr == RTC_ADDR) ? (uint32_t)(us & 0xFFFFFFFF) : (uint32_t)(us >> 32);
  // }
  // #endif
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  if (likely(in_mrom(addr))) { mrom_write(addr, len, data); return; }
  if (likely(in_sram(addr))) { sram_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
