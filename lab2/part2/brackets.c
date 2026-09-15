#include <stdio.h>

#include "str_io.h"

/* Every opening bracket must be closed by the matching bracket in the right order. */
static int brackets_ok(const char* s) {
  char stack[STR_MAX];
  int top = 0;

  for (; *s != '\0'; s++) {
    char c = *s;

    if (c == '(' || c == '[' || c == '{') {
      stack[top++] = c;
    } else if (c == ')' || c == ']' || c == '}') {
      char open = (c == ')') ? '(' : (c == ']') ? '['
                                                : '{';
      if (top == 0 || stack[--top] != open)
        return 0;
    }
  }

  return top == 0; /* the stack must be empty at the end */
}

int main(void) {
  char s[STR_MAX];

  printf("Enter a bracket expression: ");
  string_read(s, sizeof s);
  string_print("Source string", s);

  if (brackets_ok(s))
    printf("The expression is correct\n");
  else
    printf("The expression is NOT correct\n");

  return 0;
}
