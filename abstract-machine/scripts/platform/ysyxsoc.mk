AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c 


CFLAGS    += -fdata-sections -ffunction-sections $(INCFLAGS)
LDSCRIPTS += $(AM_HOME)/am/src/riscv/ysyxsoc/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x20000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
LDFLAGS   += --print-map

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --only-section=.text --only-section=.rodata --only-section=.data -O binary $(IMAGE).elf $(IMAGE).bin

ARGS += -f $(IMAGE).elf
ifeq ($(BATCH), true)
    ARGS += -b
endif

NPCFLAGS += -f $(IMAGE).elf 




VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert
VERILATOR_INC = $(addprefix -I, /home/parano1d/ysyx-workbench/ysyxSoC/perip/uart16550/rtl /home/parano1d/ysyx-workbench/ysyxSoC/perip/spi/rtl)
ALL_SOC_DIRS = $(shell find  $(NPC_HOME)../ysyxSoC/perip -type d)
ALL_NPC_DIRS = $(shell find  $(NPC_HOME)./vsrc -type d)

V_FLAGS = $(addprefix -y , $(ALL_SOC_DIRS))
V_FLAGS += $(addprefix -y , $(ALL_NPC_DIRS))
ALL_VSRC_FILES = $(shell find $(NPC_HOME)/../ysyxSoC/perip -name "*.v")
ALL_VSRC_FILES += $(shell find $(NPC_HOME)/../ysyxSoC/build -name "*.v")

CSRC = $(shell find $(abspath $(NPC_HOME)/csrc) -name "*.cpp")

run: insert-arg
	$(VERILATOR) $(VERILATOR_CFLAGS)  $(VERILATOR_INC) $(CSRC) -cc --exe --build --trace-fst -j 0\
		--timescale "1ns/1ns" --no-timing --autoflush \
		$(ALL_VSRC_FILES) $(NPC_HOME)/vsrc/ysyx_25110271.sv \
		-LDFLAGS "-lreadline -lncurses"\
		-CFLAGS "-I $(NEMU_HOME)/tools/capstone/repo/include"\
		--top-module ysyxSoCFull
	cp $(IMAGE_REL).bin $(NPC_HOME)/test.bin 
	./obj_dir/VysyxSoCFull $(ARGS)  	

.PHONY: insert-arg
