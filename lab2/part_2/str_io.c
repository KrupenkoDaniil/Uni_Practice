#include <stdio.h>
#include <string.h>

#include "str_io.h"

void string_read(char *buf, size_t size)
{
    size_t len;

    if (fgets(buf, (int)size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }

    len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')    /* drop the line feed */
        buf[len - 1] = '\0';
}

void string_print(const char *title, const char *buf)
{
    printf("%s: \"%s\"\n", title, buf);
}