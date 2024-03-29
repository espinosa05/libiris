#ifndef IRIS_ENGINE_H
#define IRIS_ENGINE_H

/* library headers */
#include "core/iris_utils.h"
#include "core/iris_getopt.h"
#include "core/iris_window.h"
#include "core/iris_types.h"
#include "core/iris_shader.h"

typedef struct iris_engine {
        struct iris_window main_window;
        bool should_close;
} Iris_Engine;

Iris_Status iris_engine_init(Iris_Engine *engine, char *instance_id);
Iris_Status iris_engine_close(Iris_Engine *engine);
Iris_Status iris_engine_poll_events(Iris_Engine *engine);

#endif /* IRIS_ENGINE_H */
