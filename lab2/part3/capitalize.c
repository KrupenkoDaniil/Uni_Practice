/* Lab 2, part III, variant 6, task 3.
   Check that all words after a full stop start with a capital letter
   and correct the string if they do not.
   The string input/output functions come from the static library libstrcase.a. */

#include <stdio.h>

#include "str_case.h"

int main(void)
{
    char s[STR_MAX];

    printf("Enter a string: ");
    string_read(s, sizeof s);
    string_print("Source string", s);

    if (sentence_starts_ok(s)) {
        printf("All words after a full stop start with a capital letter\n");
    } else {
        printf("Number of corrected words: %d\n", fix_sentence_starts(s));
        string_print("Corrected string", s);
    }

    return 0;
}