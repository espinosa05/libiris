#ifndef IRIS_ENGINE_CORE_IRIS_UTILS_H
#define IRIS_ENGINE_CORE_IRIS_UTILS_H

#include <stdio.h>
#include <stdarg.h>

void iris_log(char *tag, char *fmt, ...);

#define TODO(s) iris_log("TODO", "%s@%s:%d:\t%s\n", __func__, __FILE__, __LINE__, s)


#endif /* IRIS_ENGINE_CORE_IRIS_UTILS_H */
