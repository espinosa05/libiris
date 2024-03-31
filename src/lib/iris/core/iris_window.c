#include <iris/core/iris_window.h>
#include <iris/core/iris_utils.h>
#include <iris/core/gfx.h>
#include <stdio.h>

#define IRIS_SWAP_INTERVAL_VSYNC 1

Iris_Gfx_Status iris_window_init(struct iris_window *window, const char *title,
                                         uint32_t flags, size_t w, size_t h)
{
        GLFWmonitor *monitor = NULL;
        /* set default title */
        if (!title)
                title = "iris window";

        if (flags & IRIS_WINDOW_MAKE_FULLSCREEN)
        {
                monitor = glfwGetPrimaryMonitor();
                const GLFWvidmode *mode = glfwGetVideoMode(monitor);
                /* update width and height values */
                w = mode->width;
                h = mode->height;
        }

        window->api = glfwCreateWindow(w, h, title, monitor, NULL);
        if (!window->api)
                return IRIS_GFX_FAILED_TO_OPEN_WINDOW;

        glfwMakeContextCurrent(window->api);
        if (glewInit() != GLEW_OK)
                return IRIS_GFX_FAILED_TO_START_GL_API;

        if (flags & IRIS_WINDOW_GRAB_INPUT)
        {
                glfwSetInputMode(window->api, GLFW_CURSOR, GLFW_FALSE);
        }

        if (flags & IRIS_WINDOW_DEFAULT_INPUT_HANDLER)
        {
                TODO("default input handlers");
        }

        if (flags & IRIS_WINDOW_NEW_AUDIO)
        {
                TODO("implement audio (OpenAL)");
        }


        glfwSwapInterval(IRIS_SWAP_INTERVAL_VSYNC);

        return IRIS_GFX_SUCCESS;
}

IRIS_INLINE Iris_Gfx_Status iris_window_close(struct iris_window *window)
{
        glfwDestroyWindow(window->api);

        return IRIS_GFX_SUCCESS;
}

IRIS_INLINE bool iris_window_should_close(struct iris_window *window)
{
        return glfwWindowShouldClose(window->api);
}

IRIS_INLINE void iris_window_swap(struct iris_window *window)
{
        glfwSwapBuffers(window->api);
}

IRIS_INLINE Iris_Gfx_Status iris_window_show(struct iris_window *window)
{
        glfwShowWindow(window->api);
}

IRIS_INLINE Iris_Gfx_Status iris_window_hide(struct iris_window *window)
{
        glfwHideWindow(window->api);
}
