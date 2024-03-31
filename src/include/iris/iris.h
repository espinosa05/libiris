#ifndef IRIS_ENGINE_H
#define IRIS_ENGINE_H

/* library headers */
#include "core/iris_utils.h"
#include "core/iris_getopt.h"
#include "core/iris_window.h"
#include "core/iris_types.h"
#include "core/iris_shader.h"

#define IRIS_ENGINE_DEFAULT_WINDOW_FLAGS (IRIS_WINDOW_MAKE_FULLSCREEN | IRIS_WINDOW_GRAB_INPUT | IRIS_WINDOW_DEFAULT_INPUT_HANDLER)

struct iris_settings {
        uint32_t width;
        uint32_t height;
        uint64_t window_flags;
        const char *instance_id;
};

typedef struct iris_engine {
        struct iris_window main_window;
        bool should_close;
} Iris_Engine;

Iris_Status iris_engine_init(Iris_Engine *engine, struct iris_settings *settings);
Iris_Status iris_engine_close(Iris_Engine *engine);
Iris_Status iris_engine_start_renderer(Iris_Engine *engine);
Iris_Status iris_engine_poll_events(Iris_Engine *engine);
Iris_Status iris_engine_render_context(Iris_Engine *engine);


#endif /* IRIS_ENGINE_H */
