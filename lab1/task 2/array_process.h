/* Array processing functions used by the two programs of lab 1, part II. */

#ifndef ARRAY_PROCESS_H
#define ARRAY_PROCESS_H

/* Swaps the largest negative element with the first positive one.
   Returns 1 if the swap was made, 0 if one of the elements is absent. */
int array_swap_max_negative_first_positive(int *a, int n);

/* Inserts 0 between the 10th and the 11th elements, having shifted
   the elements starting from the 11th one to the right.
   The logical size of the array grows by one, so the buffer must have
   room for n + 1 elements. */
void array_insert_middle_zero(int *a, int *n);

#endif