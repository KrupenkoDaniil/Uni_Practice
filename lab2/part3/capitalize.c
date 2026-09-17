#include <stdio.h>

#include "str_case.h"
#define STR_MAX 256

int main(void) {
  char s[STR_MAX];

  printf("Enter a string: ");
  string_read(s, sizeof s);
  string_print("Source string", s);

  int fixed = process_sentence_starts(s, 1);
  if (fixed) {
    printf("Number of corrected words: %d\n", fixed);
    string_print("Corrected string", s);

  } else {
    printf("All words after a full stop start with a capital letter\n");
  }
  // if (sentence_starts_ok(s)) {
  //   printf("All words after a full stop start with a capital letter\n");
  // } else {
  //   printf("Number of corrected words: %d\n", fix_sentence_starts(s));
  //   string_print("Corrected string", s);
  // }

  return 0;
}
