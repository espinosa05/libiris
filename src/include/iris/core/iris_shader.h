#ifndef IRIS_ENGINE_CORE_IRIS_SHADER_H
#define IRIS_ENGINE_CORE_IRIS_SHADER_H

#include "iris_utils.h"
#include "iris_types.h"

typedef struct iris_shader {
        char *vertex_source;
        char *fragment_source;
        unsigned int id;
} Iris_Shader;

Iris_Status iris_shader_compile_and_link(Iris_Shader *shader,
                const char *fragment_source, const char *vertex_source);

Iris_Status iris_shader_use(Iris_Shader *shader);
Iris_Status iris_shader_close(Iris_Shader *shader);

#endif /* IRIS_ENGINE_CORE_IRIS_SHADER_H */
