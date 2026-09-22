#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dloader.h"

#define MATRIX_LIB "libmatrix.dll" /* LoadLibrary searches the directory */
#define ARRAY_LIB "libarray.dll"   /* of the application itself          */

int main(void) {
  int choice;

  srand((unsigned)time(NULL)); /* one seed for the whole process */

  for (;;) {
    printf("\nWhat do you want to work with?\n");
    printf("  1 - matrix Q (9x11)\n");
    printf("  2 - array R (38)\n");
    printf("  3 - quit\n");
    printf("> ");

    if (scanf("%d", &choice) != 1) break;

    if (choice == 1)
      dloader_run(MATRIX_LIB, "matrix_run");
    else if (choice == 2)
      dloader_run(ARRAY_LIB, "array_run");
    else if (choice == 3)
      break;
    else
      printf("Unknown item, try again\n");
  }

  return 0;
}
