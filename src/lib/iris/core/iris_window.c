#include <iris/core/iris_window.h>
#include <iris/core/gfx.h>
#include <stdio.h>
#define IRIS_SWAP_INTERVAL_VSYNC 1


Iris_Gfx_Status iris_window_init(struct iris_window *window, char *title,
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
        {
                printf("glfw failed to open window!\n");
                return 1;
        }
        glfwMakeContextCurrent(window->api);

        if (glewInit() != GLEW_OK)
        {
                printf("failed to start GLEW!");
                return 1;
        }

        glfwSwapInterval(IRIS_SWAP_INTERVAL_VSYNC);

        return IRIS_GFX_SUCCESS;
}

Iris_Gfx_Status iris_window_close(struct iris_window *window)
{
        glfwDestroyWindow(window->api);

        return IRIS_GFX_SUCCESS;
}

bool iris_window_should_close(struct iris_window *window)
{
        return glfwWindowShouldClose(window->api);
}

Iris_Gfx_Status iris_window_swap(struct iris_window *window)
{
        glfwSwapBuffers(window->api);
        return IRIS_GFX_SUCCESS;
}
