#include "str_case.h"

#include <stdio.h>
#include <string.h>

/* Length in bytes of the character that starts at s (ASCII or UTF-8). */

/* 1 if the character at s is a small letter (Latin or Cyrillic). */
static int is_lowercase(const char* s) {
  if (s[0] >= 'a' && s[0] <= 'z')
    return 1;
  return 0;
}

/* Replaces the small letter at s by its capital form (two bytes for Cyrillic). */
static void make_uppercase(char* s) {
  if (s[0] >= 'a' && s[0] <= 'z') {
    s[0] -= 32;
  }
}

/* Walks through the string, looking at the first letter of every word
   that follows a full stop. fix = 0 only counts them, fix = 1 corrects them. */
static int process_sentence_starts(char* s, int fix) {
  char* p = s;
  int after_dot = 0, fixed = 0;

  while (*p != '\0') {
    if (*p == '.') {
      after_dot = 1;
      p++;
      continue;
    }
    if (after_dot && *p != ' ' && *p != '\t') {
      if (is_lowercase(p)) {
        fixed++;
        if (fix)
          make_uppercase(p);
      }
      after_dot = 0;
    }
    p++;
  }

  return fixed;
}

int sentence_starts_ok(const char* s) {
  return process_sentence_starts((char*)s, 0) == 0; /* nothing is modified */
}

int fix_sentence_starts(char* s) {
  return process_sentence_starts(s, 1);
}

void string_read(char* buf, size_t size) {
  size_t len;

  if (fgets(buf, (int)size, stdin) == NULL) {
    buf[0] = '\0';
    return;
  }

  len = strlen(buf);
  if (len > 0 && buf[len - 1] == '\n')
    buf[len - 1] = '\0';
}

void string_print(const char* title, const char* buf) {
  printf("%s: \"%s\"\n", title, buf);
}
