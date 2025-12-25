ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
  } > mrom AT> mrom : text
  .rodata : {
    *(.rodata*)
  } > mrom AT> mrom
  .data : {
    *(.data*)
    *(.sdata*)
  } > sram AT> mrom : data
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  _bss_end = .;
  } > sram AT> mrom


  _data_addr = ADDR(.data);
  _data_len  = SIZEOF(.data);
  _data_loadaddr = LOADADDR(.data);

  _heap_start = .;
  _stack_start = _heap_start + 0x1000;
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
}
