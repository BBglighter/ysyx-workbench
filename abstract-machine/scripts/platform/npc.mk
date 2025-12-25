AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

ARGS += -f $(IMAGE).elf
ifeq ($(BATCH), true)
    ARGS += -b
endif

NPCFLAGS += -f $(IMAGE).elf 
run: insert-arg
	verilator -cc --exe --build --trace-fst  $(NPC_HOME)/vsrc/Top.sv $(wildcard $(NPC_HOME)/csrc/*.cpp) \
		-LDFLAGS "-lreadline -lncurses" -CFLAGS "-I $(NEMU_HOME)/tools/capstone/repo/include"
	cp $(IMAGE_REL).bin $(NPC_HOME)/test.bin 
	./obj_dir/VysyxSoCFull $(ARGS)  	

.PHONY: insert-arg
