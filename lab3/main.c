/* Lab 3, variant 6.
   Count the elements of matrix Q(9x11) and array R(38) whose remainder
   after division by five is equal to one.
   The handling functions live in two dynamic libraries; the library that
   is actually used is loaded at run time, after the user chooses the menu item. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dloader.h"

#ifdef _WIN32
#define MATRIX_LIB "matrixlib.dll"      /* LoadLibrary searches the directory */
#define ARRAY_LIB  "arraylib.dll"       /* of the application itself          */
#else
/* The names do not contain a slash, so the dynamic loader searches the run
   path recorded in the program (-Wl,-rpath,$ORIGIN), that is the directory
   where the executable lies.  The working directory does not matter. */
#define MATRIX_LIB "libmatrixlib.so"
#define ARRAY_LIB  "libarraylib.so"
#endif

int main(void)
{
    int choice;

    srand((unsigned)time(NULL));    /* one seed for the whole process */

    for (;;) {
        printf("\nWhat do you want to work with?\n");
        printf("  1 - matrix Q (9x11)\n");
        printf("  2 - array R (38)\n");
        printf("  3 - quit\n");
        printf("> ");

        if (scanf("%d", &choice) != 1)
            break;

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