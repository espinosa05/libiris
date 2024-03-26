#ifndef IRIS_ENGINE_H
#define IRIS_ENGINE_H

/* library headers */
#include "core/iris_utils.h"
#include "core/iris_getopt.h"
#include "core/iris_window.h"

enum iris_engine_status_codes {
        IRIS_ENGINE_SUCCESS = 0,
        IRIS_ENGINE_FAILED_TO_START_GLFW,

        IRIS_ENGINE_N_STATUS,
#define IRIS_ENGINE_UNKOWN IRIS_ENGINE_N_STATUS
};

typedef struct iris_engine {
        struct iris_window main_window;
} Iris_Engine;

Iris_Status init_iris_engine(Iris_Engine *engine);
Iris_Status close_iris_engine(Iris_Engine *engine);

#endif /* IRIS_ENGINE_H */
