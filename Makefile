EXE = # .exe
part_1 = ./lab2/part1
part_2 = ./lab2/part2
part_3 = ./lab2/part3


.PHONY: all task_1 task_2 task_3 clean

# Compile all 
all: task_1 task_2 task_3

task_1: $(part_1)/factorial$(EXE)

$(part_1)/factorial$(EXE): $(part_1)/factorial.c
	gcc -g $< -o $@

task_2: $(part_2)/brackets$(EXE)

$(part_2)/brackets$(EXE): $(part_2)/brackets.c $(part_2)/str_io.c
	gcc -g $< $(part_2)/str_io.c -o $@

task_3: $(part_3)/capitalize$(EXE) 

$(part_3)/capitalize$(EXE): $(part_3)/capitalize.o $(part_3)/libstr.a
	gcc $< -o $@ -L$(part_3) -lstr

$(part_3)/capitalize.o: $(part_3)/capitalize.c
	gcc -g -c $< -o $@

$(part_3)/libstr.a: $(part_3)/str_case.o
	ar rcs $@ $<

$(part_3)/str_case.o: $(part_3)/str_case.c
	gcc -c $< -o $@

clean:
	-del "$(part_1)\factorial.exe" "$(part_2)\brackets.exe"
	-del "$(part_3)\capitalize.exe" "$(part_3)\capitalize.o" "$(part_3)\str_case.o" "$(part_3)\libstr.a"
# 	rm -f "$(part_1)/factorial.exe" "$(part_2)/brackets.exe"
# 	rm -f "$(part_3)/capitalize.exe" "$(part_3)/capitalize.o" "$(part_3)/str_case.o" "$(part_3)/libstr.a"