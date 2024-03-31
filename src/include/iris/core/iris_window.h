#ifndef IRIS_ENGINE_CORE_IRIS_WINDOW_H
#define IRIS_ENGINE_CORE_IRIS_WINDOW_H

#include "iris_types.h"
#include "iris_macros.h"

struct iris_window {
        void *api;
};

enum iris_window_flags {
        IRIS_WINDOW_MAKE_FULLSCREEN = 1,
        IRIS_WINDOW_GRAB_INPUT = 2,
        IRIS_WINDOW_DEFAULT_INPUT_HANDLER = 4,
        IRIS_WINDOW_NEW_AUDIO = 8,
};

typedef Iris_Status Iris_Gfx_Status;

enum iris_gfx_status_codes {
        IRIS_GFX_SUCCESS = 0,
        IRIS_GFX_FAILED_TO_OPEN_WINDOW,
        IRIS_GFX_FAILED_TO_START_GL_API,
        IRIS_GFX_N_STATUS,
#define IRIS_GFX_UNKOWN IRIS_GFX_N_STATUS
};

#define IRIS_WINDOW_WIDTH_UNDEFINED 0
#define IRIS_WINDOW_HEIGHT_UNDEFINED 0

Iris_Gfx_Status iris_window_init(struct iris_window *window, const char *title, uint32_t flags, size_t w, size_t h);
IRIS_INLINE bool iris_window_should_close(struct iris_window *window);
IRIS_INLINE void iris_window_swap(struct iris_window *window);
IRIS_INLINE Iris_Gfx_Status iris_window_close(struct iris_window *window);
IRIS_INLINE Iris_Gfx_Status iris_window_show(struct iris_window *window);

#endif /* IRIS_ENGINE_CORE_IRIS_WINDOW_H */
