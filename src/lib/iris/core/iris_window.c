#include "../../../include/iris/core/iris_window.h"

#define IRIS_SWAP_INTERVAL_VSYNC 1

Iris_Gfx_Status iris_gfx_create_window(struct iris_window *window, uint32_t flags,
                                        char *title, size_t w, size_t h)
{
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();

        /* set default title */
        if (!title)
                title = "iris window";

        if (flags & IRIS_WINDOW_MAKE_FULLSCREEN) {
                const GLFWvidmode *mode = glfwGetVideoMode(monitor);
                /* update width and height values */
                w = mode->width;
                h = mode->height;
        }

        window->api = glfwCreateWindow(w, h, title, monitor, NULL);
        glfwMakeContextCurrent(window->api);
        glfwSwapInterval(IRIS_SWAP_INTERVAL_VSYNC);

        return IRIS_GFX_SUCCESS;
}

Iris_Gfx_Status iris_gfx_destroy_window(struct iris_window *window)
{
        glfwDestroyWindow(window->api);

        return IRIS_GFX_SUCCESS;
}

