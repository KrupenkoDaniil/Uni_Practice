/* Dynamic library with matrix handling (lab 3, variant 6, matrix Q(9x11)). */

#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H

#ifdef _WIN32
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT
#endif

#define MATRIX_ROWS 9
#define MATRIX_COLS 11

LIB_EXPORT void matrix_fill(int a[MATRIX_ROWS][MATRIX_COLS]);
LIB_EXPORT void matrix_print(const char *title, const int a[MATRIX_ROWS][MATRIX_COLS]);
LIB_EXPORT int  matrix_count_rem5_is1(const int a[MATRIX_ROWS][MATRIX_COLS]);

/* Entry point called by the main program after loading the library. */
LIB_EXPORT void matrix_run(void);

#endif