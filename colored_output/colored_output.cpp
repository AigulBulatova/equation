#include <stdarg.h>
#include <stdio.h>
#include "colored_output.h"

void colored_print(const char *color, const char *format, ...)
{
    printf("%s", color);

    va_list ptr = {};
    va_start(ptr, format);
    vprintf(format, ptr);
    va_end(ptr);

    printf(RESET);
}