# Compilation

```console
gcc -E -o task_1.i task_1.c      # 1. preprocessor
gcc -S -O2 -o task_1.c  # 2. compiler -> assembler
gcc -c -o task_1.o task_1.c   # 3. assembler
gcc -o task_1 task_1.o           # 4. linker
```

# Optimization

```console
gcc -S -O1 array_io.c -o array_io_1.s
gcc -S -O2 array_io.c -o array_io_2.s
gcc -S -O3 array_io.c -o array_io_3.s
```

# Library

```console
ar crs libarray.a array_io.o array_process.o
```
