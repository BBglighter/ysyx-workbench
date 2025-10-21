all:
	@echo "Write this Makefile by your self."


SRC = top.v
CPP = sim.cpp
VERILATOR_FLAGS = --cc --exe --build -j 0 --Wall --trace-fst

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator $(VERILATOR_FLAGS) $(SRC) $(CPP)

clean:
	rm -rf obj_dir

  
include ../Makefile
