#ifndef ARRAY_LIB_H
#define ARRAY_LIB_H

#ifdef _WIN32
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT
#endif

#define ARRAY_SIZE 38

LIB_EXPORT void array_fill(int* a, int n);
LIB_EXPORT void array_print(const char* title, const int* a, int n);
LIB_EXPORT int array_count_rem5_is1(const int* a, int n);

/* Entry point called by the main program after loading the library. */
LIB_EXPORT void array_run(void);

#endif
