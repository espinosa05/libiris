#ifndef IRIS_ENGINE_CORE_IRIS_TYPES_H
#define IRIS_ENGINE_CORE_IRIS_TYPES_H

#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

typedef ssize_t Iris_Status;

enum iris_engine_status_codes {
        IRIS_ENGINE_SUCCESS = 0,
        IRIS_ENGINE_FAILED_TO_START_GLFW,
        IRIS_ENGINE_FAILED_TO_START_GL_API,

        IRIS_ENGINE_N_STATUS,
#define IRIS_ENGINE_UNKOWN IRIS_ENGINE_N_STATUS
};

typedef struct vec_2 {
        ssize_t x;
        ssize_t y;
} Vec2;

typedef struct vec_3 {
        ssize_t x;
        ssize_t y;
        ssize_t z;
} Vec3;


#endif /* IRIS_ENGINE_CORE_IRIS_TYPES_H */
