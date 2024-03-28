#include "../../../include/iris/core/iris_utils.h"
#include "../../../include/iris/core/iris_types.h"

#include <stdio.h>

ssize_t get_file_size(FILE *file)
{
        ssize_t file_size = 0;
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);
        rewind(file);

        return file_size;
}

void impl_iris_log(char *tag, char *fmt, ...)
{
        va_list ap;
        va_start(ap, fmt);
        fprintf(stderr, "[%s] ", tag);
        vfprintf(stderr, fmt, ap);
        putc('\n', stderr);
        va_end(ap);
}

char *iris_util_load_file_contents(char *path)
{
        ssize_t file_size = 0;
        char *file_buffer = NULL;
        FILE *file = fopen(path, "r");

        if (file)
        {
                iris_info_log("opened file '%s'", path);
                file_size = get_file_size(file);
                file_buffer = iris_malloc(sizeof(char), file_size + NULL_TERM_SIZE);
                fread(file_buffer, sizeof(char), file_size, file);
                file_buffer[file_size] = '\0';

                fclose(file);
        }

        return file_buffer;
}
