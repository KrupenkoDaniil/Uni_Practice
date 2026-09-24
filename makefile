EXE      =

# ---- directories -----------------------------------------------------------
L1A = lab1/part_1
L1B = lab1/part_2
L2A = lab2/part_1
L2B = lab2/part_2
L2C = lab2/part_3
L3  = lab3/

# ---- source files ----------------------------------------------------------
L1A_SRC   = $(L1A)/task_1.c

L1B_IO    = $(L1B)/array_io.c
L1B_PROC  = $(L1B)/array_process.c
L1B_P2    = $(L1B)/task_2.c
L1B_P3    = $(L1B)/task_2.c

L2A_SRC   = $(L2A)/factorial.c
L2B_IO    = $(L2B)/str_io.c
L2B_BRACK = $(L2B)/brackets.c
L2C_LIB   = $(L2C)/str_case.c
L2C_CAP   = $(L2C)/capitalize.c

L3_MAIN   = $(L3)/main.c
L3_LOAD   = $(L3)/dloader.c
L3_MAT    = $(L3)/matrix_lib.c
L3_ARR    = $(L3)/array_lib.c

# ---- groups of targets -----------------------------------------------------
.PHONY: all clean lab1 lab2 lab3 \
        lab1_part1 lab1_part2 lab1_stages lab1_optim lab1_part2_lib \
        lab2_part1 lab2_part2 lab2_part3

all: lab1 lab2 lab3

lab1: lab1_part1 lab1_part2

lab2: lab2_part1 lab2_part2 lab2_part3

lab3: $(L3)/main$(EXE) $(L3)/matrix_lib.so $(L3)/array_lib.so

# Lab 1, part I.

lab1_part1: $(L1A)/task_1$(EXE)

$(L1A)/task_1$(EXE): $(L1A_SRC)
	gcc  $(OPT) -o $@ $<

# the stages that gcc performs one by one
lab1_stages: $(L1A)/task_1.i $(L1A)/task_1.s $(L1A)/task_1.o

$(L1A)/task_1.i: $(L1A_SRC)
	gcc -E -o $@ $<               # preprocessor only

$(L1A)/task_1.s: $(L1A_SRC)
	gcc -S $(OPT) -o $@ $<        # compile to assembler

$(L1A)/task_1.o: $(L1A_SRC)
	gcc  -c -o $@ $<     # compile to an object file

# the same source compiled with different levels of optimisation
lab1_optim: $(L1A)/task_1_O0.s $(L1A)/task_1_O1.s \
            $(L1A)/task_1_O2.s $(L1A)/task_1_O3.s

$(L1A)/task_1_O0.s: $(L1A_SRC)
	gcc -S -O0 -o $@ $<

$(L1A)/task_1_O1.s: $(L1A_SRC)
	gcc -S -O1 -o $@ $<

$(L1A)/task_1_O2.s: $(L1A_SRC)
	gcc -S -O2 -o $@ $<

$(L1A)/task_1_O3.s: $(L1A_SRC)
	gcc -S -O3 -o $@ $<

# Lab 1, part II.

lab1_part2: $(L1B)/task_2$(EXE) $(L1B)/task_3$(EXE) $(L1B)/libarrays.a

$(L1B)/array_io.o: $(L1B_IO) $(L1B)/array_io.h
	gcc -c -o $@ $<

$(L1B)/array_process.o: $(L1B_PROC) $(L1B)/array_process.h
	gcc -c -o $@ $<

# both programs are linked with the same array_io.o
$(L1B)/task_2$(EXE): $(L1B_P2) $(L1B)/array_io.o $(L1B)/array_process.o
	gcc -o $@ $^

$(L1B)/prog3_insert$(EXE): $(L1B_P3) $(L1B)/array_io.o $(L1B)/array_process.o
	gcc -o $@ $^

$(L1B)/libarrays.a: $(L1B)/array_io.o $(L1B)/array_process.o
	$(AR) crs $@ $^

# the same programs, but the array functions are taken from libarrays.a
lab1_part2_lib: $(L1B)/task_2$(EXE) $(L1B)/task_3$(EXE)

$(L1B)/task_2$(EXE): $(L1B_P2) $(L1B)/libarrays.a
	gcc  $(OPT) -o $@ $< -L$(L1B) -larrays

$(L1B)/task_3$(EXE): $(L1B_P3) $(L1B)/libarrays.a
	gcc  $(OPT) -o $@ $< -L$(L1B) -larrays

# ============================================================================
#  Lab 2.  All the programs are built with the debug information (-g),
#  because they are studied under gdb.
# ============================================================================

lab2_part1: $(L2A)/factorial$(EXE)

$(L2A)/factorial$(EXE): $(L2A_SRC)
	gcc -g -o $@ $<

lab2_part2: $(L2B)/brackets$(EXE)

$(L2B)/str_io.o: $(L2B_IO) $(L2B)/str_io.h
	gcc -g -c -o $@ $<

$(L2B)/brackets$(EXE): $(L2B_BRACK) $(L2B)/str_io.o
	gcc -g -o $@ $^

lab2_part3: $(L2C)/capitalize$(EXE) $(L2C)/libstrcase.a

$(L2C)/str_case.o: $(L2C_LIB) $(L2C)/str_case.h
	gcc -g -c -o $@ $<

$(L2C)/libstrcase.a: $(L2C)/str_case.o
	ar crs $@ $^

$(L2C)/capitalize$(EXE): $(L2C_CAP) $(L2C)/libstrcase.a
	gcc -g -o $@ $< -L$(L2C) -lstrcase

# Lab 3.

$(L3)/%.o: $(L3)/%.c
	gcc  $(PIC) -c -o $@ $<

$(L3)/matrix_lib.so: $(L3)/matrix_lib.o
	gcc -shared -o $@ $<

$(L3)/array_lib.so: $(L3)/array_lib.o
	gcc -shared -o $@ $<

$(L3)/main$(EXE): $(L3_MAIN) $(L3)/dloader.o
	gcc $< -Wl,-rpath,'$$ORIGIN' -o $@ ./lab3/dloader.o

#  Clean

clean:
	rm -f $(L1A)/task_1$(EXE) $(L1A)/*.o $(L1A)/*.i $(L1A)/*.s
	rm -f $(L1B)/task_2$(EXE) $(L1B)/task_3$(EXE)
	rm -f $(L1B)/*.o $(L1B)/*.a
	rm -f $(L2A)/factorial$(EXE) $(L2A)/*.o
	rm -f $(L2B)/brackets$(EXE) $(L2B)/*.o
	rm -f $(L2C)/capitalize$(EXE) $(L2C)/*.o $(L2C)/*.a
	rm -f $(L3)/matrixlib_app$(EXE) $(L3)/*.o $(L3)/*.so
