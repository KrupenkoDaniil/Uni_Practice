#include "array_process.h"

/* Index of the largest negative element, or -1 if there is no negative one. */
static int max_negative_index(const int* a, int n) {
  int i, idx = -1;

  for (i = 0; i < n; i++)
    if (a[i] < 0 && (idx == -1 || a[i] > a[idx]))
      idx = i;
  return idx;
}

/* Index of the first positive element, or -1 if there is no positive one. */
static int first_positive_index(const int* a, int n) {
  int i;

  for (i = 0; i < n; i++)
    if (a[i] > 0)
      return i;
  return -1;
}

int array_swap_max_negative_first_positive(int* a, int n) {
  int i = max_negative_index(a, n);
  int j = first_positive_index(a, n);
  int t;

  if (i == -1 || j == -1)
    return 0;

  t = a[i];
  a[i] = a[j];
  a[j] = t;
  return 1;
}

void array_insert_middle_zero(int* a, int* n) {
  int i;
  int middle = *n / 2;

  for (i = *n; i > middle; i--) /* shift the tail (from the 11th element) to the right */
    a[i] = a[i - 1];
  a[middle] = 0;
  (*n)++;
}
