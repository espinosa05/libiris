#include "../../../include/iris/core/iris_utils.h"

#include <stdio.h>

void iris_log(char *tag, char *fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        fprintf(stderr, "[%s] ", tag);
        vfprintf(stderr, fmt, ap);
        putc('\n', stderr);
        va_end(ap);
}
