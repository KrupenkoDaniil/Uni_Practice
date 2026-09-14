/* Lab 1, part II, variant 6, program 3.
   Insert 0 into the middle of array M(20), having shifted the elements
   starting from the 11th one to the right. */

#include <stdio.h>

#include "array_io.h"
#include "array_process.h"

#define N 20

int main(void)
{
    int m[N + 1];               /* one spare cell for the inserted element */
    int n = N;

    array_read(m, n);
    array_print("Source array M", m, n);

    array_insert_middle_zero(m, &n);
    array_print("After inserting 0 in the middle", m, n);

    return 0;
}