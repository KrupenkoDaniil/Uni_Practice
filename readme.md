Building libraries

```bash
gcc -fPIC -shared array_lib.c -o libarray.so
gcc -fPIC -shared matrix_lib.c -o libmatrix.so
gcc -c dloader.c -o dloader.o
gcc main.c -Wl,-rpath,'$ORIGIN' -o task dloader.o

```
