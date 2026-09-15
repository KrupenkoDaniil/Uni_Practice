/* Static library for lab 2, part III: string input/output and
   capitalisation of the words that follow a full stop. */

#ifndef STR_CASE_H
#define STR_CASE_H

#include <stddef.h>

#define STR_MAX 256

void string_read(char *buf, size_t size);
void string_print(const char *title, const char *buf);

/* 1 if every word after a '.' starts with a capital letter. */
int sentence_starts_ok(const char *s);

/* Makes the first letter of such words capital; returns the number of fixes. */
int fix_sentence_starts(char *s);

#endif