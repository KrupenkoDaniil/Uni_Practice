EXE = .exe
LIB = .dll 

.PHONY: all clean

all: ./lab3/task$(EXE)

./lab3/task$(EXE): ./lab3/main.c ./lab3/dloader.o ./lab3/libarray$(LIB) ./lab3/libmatrix$(LIB)
	gcc $< -Wl,-rpath,'$$ORIGIN' -o $@ ./lab3/dloader.o

./lab3/dloader.o: ./lab3/dloader.c
	gcc -c $< -o $@

./lab3/libarray$(LIB): ./lab3/array_lib.c
	gcc -fPIC -shared $< -o $@

./lab3/libmatrix$(LIB): ./lab3/matrix_lib.c
	gcc -fPIC -shared $< -o $@

clean:
	-del ".\lab3\task$(EXE)" ".\lab3\dloader.o" ".\lab3\libarray.dll" ".\lab3\libmatrix.dll"