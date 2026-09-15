#include <stdio.h>

int main(void) {
  int n, f;
  int k;

  printf("Enter a natural number N: ");
  if (scanf("%d", &n) != 1 || n < 1) {
    printf("N must be a natural number\n");
    return 1;
  }

  f = 1;
  k = 1;
  while (f < n) {
    k++;
    f *= k;
  }

  if (f == n) {
    printf("%d = %d!", n, k);
    if (n == 1)
      printf("  (and 0! = 1 too)");
    putchar('\n');
  } else {
    printf("%d is not a factorial of any natural number\n", n);
  }

  return 0;
}
