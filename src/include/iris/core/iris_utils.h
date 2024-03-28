#ifndef IRIS_ENGINE_CORE_IRIS_UTILS_H
#define IRIS_ENGINE_CORE_IRIS_UTILS_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <stddef.h>

#define NULL_TERM_SIZE 1

void impl_iris_log(char *tag, char *fmt, ...);
char *iris_util_load_file_contents(char *path);
ssize_t get_file_size(FILE *file);

#ifdef LOG
# define iris_log impl_iris_log
#else
# define iris_log(...) do { } while (0)
#endif /* LOG */

#define TODO(s) iris_log("TODO", "%s@%s:%d:\t%s", __func__, __FILE__, __LINE__, s)

#define iris_malloc(bs, nb) malloc(bs*nb)
#define iris_free(a) free(a)

#define iris_assert(expr, ...)                  \
                        do {                    \
                                if (!(expr)) {  \
                                        iris_log("ASSERT", "Assertion: '"#expr"' failed!" __VA_ARGS__); \
                                        exit(1); \
                                }               \
                        } while (0)

#define iris_info_log(...) iris_log("INFO", __VA_ARGS__)

#endif /* IRIS_ENGINE_CORE_IRIS_UTILS_H */
