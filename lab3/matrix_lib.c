#include <stdio.h>
#include <stdlib.h>

#include "matrix_lib.h"

/* Remainder of division by five in the range 0..4 for both signs of x. */
static int positive_mod5(int x)
{
    int r = x % 5;

    return (r < 0) ? r + 5 : r;
}

LIB_EXPORT void matrix_fill(int a[MATRIX_ROWS][MATRIX_COLS])
{
    int i, j;

    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            a[i][j] = rand() % 101 - 50;    /* random numbers from -50 to 50 */
}

LIB_EXPORT void matrix_print(const char *title, const int a[MATRIX_ROWS][MATRIX_COLS])
{
    int i, j;

    printf("%s:\n", title);
    for (i = 0; i < MATRIX_ROWS; i++) {
        for (j = 0; j < MATRIX_COLS; j++)
            printf("%5d", a[i][j]);
        putchar('\n');
    }
}

LIB_EXPORT int matrix_count_rem5_is1(const int a[MATRIX_ROWS][MATRIX_COLS])
{
    int i, j, count = 0;

    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            if (positive_mod5(a[i][j]) == 1)
                count++;
    return count;
}

LIB_EXPORT void matrix_run(void)
{
    int q[MATRIX_ROWS][MATRIX_COLS];

    matrix_fill(q);
    printf("\n=== matrix library ===\n");
    matrix_print("Matrix Q", q);
    printf("Elements with remainder 1 after division by five: %d\n",
           matrix_count_rem5_is1(q));
}