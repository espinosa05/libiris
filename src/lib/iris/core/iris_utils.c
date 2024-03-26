#include "../../../include/iris/core/iris_utils.h"

#include <stdio.h>
#include <stdarg.h>

void iris_log(char *tag, char *fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        fprintf(stderr, "[%s] ", tag);
        vfprintf(stderr, fmt, ap);
        va_end(ap);
}
