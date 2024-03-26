#ifndef IRIS_ENGINE_CORE_IRIS_WINDOW_H
#define IRIS_ENGINE_CORE_IRIS_WINDOW_H

#include "iris_types.h"
#include <GLFW/glfw3.h>

struct iris_window {
        GLFWwindow *api;
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

Iris_Gfx_Status iris_gfx_create_window(struct iris_window *window, uint32_t flags, char *title, size_t w, size_t h);
Iris_Gfx_Status iris_gfx_destroy_window(struct iris_window *window);

#endif /* IRIS_ENGINE_CORE_IRIS_WINDOW_H */
