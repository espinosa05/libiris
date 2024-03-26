#ifndef IRIS_ENGINE_CORE_IRIS_UTILS_H
#define IRIS_ENGINE_CORE_IRIS_UTILS_H

#include <stdarg.h>
void iris_log(char *tag, char *fmt, ...);

#define TODO(s) iris_log("TODO", "%s@%s:%d:\t%s", __func__, __FILE__, __LINE__, s)

#define iris_info_log(...) iris_log("INFO", __VA_ARGS__)

#endif /* IRIS_ENGINE_CORE_IRIS_UTILS_H */
