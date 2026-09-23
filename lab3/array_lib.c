#include <stdio.h>
#include <stdlib.h>

#include "array_lib.h"

/* Remainder of division by five in the range 0..4 for both signs of x.
   In C the remainder keeps the sign of the dividend: -6 % 5 == -1. */
static int positive_mod5(int x)
{
    int r = x % 5;

    return (r < 0) ? r + 5 : r;
}

LIB_EXPORT void array_fill(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
        a[i] = rand() % 101 - 50;       /* random numbers from -50 to 50 */
}

LIB_EXPORT void array_print(const char *title, const int *a, int n)
{
    int i;

    printf("%s:\n", title);
    for (i = 0; i < n; i++) {
        printf("%5d", a[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    if (n % 10 != 0)
        putchar('\n');
}

LIB_EXPORT int array_count_rem5_is1(const int *a, int n)
{
    int i, count = 0;

    for (i = 0; i < n; i++)
        if (positive_mod5(a[i]) == 1)
            count++;
    return count;
}

LIB_EXPORT void array_run(void)
{
    int r[ARRAY_SIZE];

    array_fill(r, ARRAY_SIZE);
    printf("\n=== array library ===\n");
    array_print("Array R", r, ARRAY_SIZE);
    printf("Elements with remainder 1 after division by five: %d\n",
           array_count_rem5_is1(r, ARRAY_SIZE));
}