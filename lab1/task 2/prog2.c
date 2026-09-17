#include <stdio.h>

#include "array_io.h"
#include "array_process.h"

#define N 18

int main(void) {
  int b[N];

  array_read(b, N);
  array_print("Source array B", b, N);

  if (array_swap_max_negative_first_positive(b, N))
    array_print("After the swap", b, N);
  else
    printf("Swap is impossible: the array has no negative or no positive element\n");

  return 0;
}
