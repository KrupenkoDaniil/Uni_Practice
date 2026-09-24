/* String input/output for lab 2, part II. */

#ifndef STR_IO_H
#define STR_IO_H

#include <stddef.h>

#define STR_MAX 256

void string_read(char *buf, size_t size);
void string_print(const char *title, const char *buf);

#endif