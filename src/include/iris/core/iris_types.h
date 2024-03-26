#ifndef IRIS_ENGINE_CORE_IRIS_TYPES_H
#define IRIS_ENGINE_CORE_IRIS_TYPES_H

#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>

typedef ssize_t Iris_Status;

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
