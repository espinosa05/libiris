#ifndef IRIS_ENGINE_CORE_IRIS_WINDOW_H
#define IRIS_ENGINE_CORE_IRIS_WINDOW_H
#define GLFW_INCLUDE_NONE
#include "iris_types.h"

struct iris_window {
        void *api;
};

enum iris_window_flags {
        IRIS_WINDOW_MAKE_FULLSCREEN = 1,
        IRIS_WINDOW_NEW_AUDIO = 1 << 1,
};

typedef Iris_Status Iris_Gfx_Status;

enum iris_gfx_status_codes {
        IRIS_GFX_SUCCESS = 0,

        IRIS_GFX_N_STATUS,
#define IRIS_GFX_UNKOWN IRIS_GFX_N_STATUS
};

#define IRIS_WINDOW_WIDTH_UNDEFINED 0
#define IRIS_WINDOW_HEIGHT_UNDEFINED 0

Iris_Gfx_Status iris_window_init(struct iris_window *window, char *title, uint32_t flags, size_t w, size_t h);
Iris_Gfx_Status iris_window_close(struct iris_window *window);
Iris_Gfx_Status iris_window_swap(struct iris_window *window);
bool iris_window_should_close(struct iris_window *window);
#endif /* IRIS_ENGINE_CORE_IRIS_WINDOW_H */
