# Variables
EXE =# .exe
part_1 = ./lab1/part_1
part_2 = ./lab1/part_2
task_1 = $(part_1)/task_1
task_2 = $(part_2)/task_2
task_3 = $(part_2)/task_3
IO = $(part_2)/array_io
PR = $(part_2)/array_process
# Groups of targets
.PHONY: all optimized clean

# Compile all 
all: task_1 task_2 task_3


# task 1
task_1: $(task_1)$(EXE)

$(task_1)$(EXE): $(task_1).o # run
	gcc $< -o $@

$(task_1).o: $(task_1).s # object
	gcc -c $< -o $@

$(task_1).s: $(task_1).i # assembler
	gcc -S $< -o $@

$(task_1).i: $(task_1).c
	gcc -E $< -o $@

# task 2
task_2: $(task_2)$(EXE)

$(task_2)$(EXE): $(task_2).o $(part_2)/libarray.a
	gcc $< -o $@ -L$(part_2) -larray

$(task_2).o: $(task_2).c
	gcc -c $< -o $@

# task 3
task_3: $(task_3)$(EXE)

$(task_3)$(EXE): $(task_3).o $(part_2)/libarray.a
	gcc $< -o $@ -L$(part_2) -larray

$(task_3).o: $(task_3).c
	gcc -c $< -o $@

# Library
$(part_2)/libarray.a: $(IO).o $(PR).o
	ar rcs $@ $(IO).o $(PR).o

$(IO).o: $(IO).c $(IO).h
	gcc -c $< -o $@

$(PR).o: $(PR).c $(PR).h
	gcc -c $< -o $@

# Optimized
optimized: $(task_1)_O0.s $(task_1)_O3.s

$(task_1)_O0.s: $(task_1).c
	gcc -S -O0 $< -o $@


$(task_1)_O3.s: $(task_1).c
	gcc -S -O3 $< -o $@

clean:
	-del "$(part_1)\task_1$(EXE)" "$(part_1)\task_1.o" "$(part_1)\task_1.i" "$(part_1)\task_1.s" "$(part_1)\task_1_O0.s" "$(part_1)\task_1_O3.s"
	-del "$(part_2)\task_2$(EXE)" "$(part_2)\task_2.o"
	-del "$(part_2)\task_3$(EXE)" "$(part_2)\task_3.o"
	
	rm -f "$(part_1)/task_1$(EXE)" "$(part_1)/task_1.o" "$(part_1)/task_1.i" "$(part_1)/task_1.s" "$(part_1)/task_1_O0.s" "$(part_1)/task_1_O3.s"
	rm -f "$(part_2)/task_2$(EXE)" "$(part_2)/task_2.o"
	rm -f "$(part_2)/task_3$(EXE)" "$(part_2)/task_3.o"
	rm -f "$(part_2)/array_io.o" "$(part_2)/array_process.o" "$(part_2)/libarray.a"$(DEL) "$(part_2)/array_io.o" "$(part_2)/array_process.o" "$(part_2)/libarray.a"
