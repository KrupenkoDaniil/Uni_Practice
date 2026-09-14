/* Lab 1, part I, variant 6, task 1.
   Sum of positive integers from the range [A, B] that are multiples of four. */

#include <stdio.h>

int main(void) {
  int a, b, n, sum = 0;

  printf("Enter A and B: ");
  if (scanf("%d %d", &a, &b) != 2) {
    printf("Wrong input\n");
    return 1;
  }

  if (a > b) { /* the range may be entered in any order */
    int t = a;
    a = b;
    b = t;
  }

  for (n = a; n <= b; n++)
    if (n > 0 && n % 4 == 0)
      sum += n;

  printf("Sum of positive multiples of four in [%d, %d] = %d\n", a, b, sum);
  return 0;
}
