BUILD_DIR = ./build



PRJ = chisel
mill = ./mill
test:
	$(mill) -i $(PRJ).test

verilog:
	$(call git_commit, "generate verilog")
	mkdir -p ./vsrc
	$(mill) -i $(PRJ).runMain Elaborate --target-dir ./vsrc

help:
	$(mill) -i $(PRJ).runMain Elaborate --help

reformat:
	$(mill) -i __.reformat

checkformat:
	$(mill) -i __.checkFormat

bsp:
	$(mill) -i $(mill).bsp.BSP/install

idea:
	$(mill) -i $(mill).idea.GenIdea/idea



.PHONY: test verilog help reformat checkformat clean


-include ../Makefile


TOPNAME = detectkey
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.sv")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

sim:
	$(VERILATOR) -cc --exe --build --trace-fst -j vsrc/Top.sv csrc/sim_main.cpp
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

sim_nvboard: $(BIN) 
	@$^
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!


clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!



# ######################################################################
# #
# # DESCRIPTION: Verilator Example: Small Makefile
# #
# # This calls the object directory makefile.  That allows the objects to
# # be placed in the "current directory" which simplifies the Makefile.
# #
# # This file ONLY is placed under the Creative Commons Public Domain, for
# # any use, without warranty, 2020 by Wilson Snyder.
# # SPDX-License-Identifier: CC0-1.0
# #
# ######################################################################
# # Check for sanity to avoid later confusion

# ifneq ($(words $(CURDIR)),1)
#  $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
# endif

# ######################################################################

# # This is intended to be a minimal example.  Before copying this to start a
# # real project, it is better to start with a more complete example,
# # e.g. examples/make_tracing_c.

# # If $VERILATOR_ROOT isn't in the environment, we assume it is part of a
# # package install, and verilator is in your path. Otherwise find the
# # binary relative to $VERILATOR_ROOT (such as when inside the git sources).
# ifeq ($(VERILATOR_ROOT),)
# VERILATOR = verilator
# else
# export VERILATOR_ROOT
# VERILATOR = $(VERILATOR_ROOT)/bin/verilator
# endif

# default:
#         @echo "-- Verilator hello-world simple example"
#         @echo "-- VERILATE & BUILD --------"
#         $(VERILATOR) -cc --exe --build -j vsrc/Top.sv csrc/sim_main.cpp
#         @echo "-- RUN ---------------------"
#         obj_dir/Vtop
#         @echo "-- DONE --------------------"
#         @echo "Note: Once this example is understood, see examples/make_tracing_c."
#         @echo "Note: See also https://verilator.org/guide/latest/examples.html"

# ######################################################################

# maintainer-copy::
# clean mostlyclean distclean maintainer-clean::
#         -rm -rf obj_dir *.log *.dmp *.vpd core
