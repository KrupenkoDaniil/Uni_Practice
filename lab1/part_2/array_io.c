#include <stdio.h>

#include "array_io.h"

void array_read(int *a, int n)
{
    int i;

    printf("Enter %d integers separated by spaces:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void array_print(const char *title, const int *a, int n)
{
    int i;

    printf("%s:", title);
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    putchar('\n');
}