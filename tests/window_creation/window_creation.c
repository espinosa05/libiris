#include <stdio.h>
#include <stdlib.h>
#include <iris/iris.h>
#include <GLFW/glfw3.h>

void close_test(GLFWwindow* window, int key, int scancode, int action, int mods)
{
        if (action == GLFW_PRESS)
        {
                switch (key) {
                case GLFW_KEY_ESCAPE:
                        glfwSetWindowShouldClose(window, true);
                        break;
                default:
                        printf("keycode:%d\n", key);
                }
        }
}

int main(int argc, char **argv)
{
        Iris_Engine engine;
        iris_engine_init(&engine, "window_creation");
        glfwSetKeyCallback(engine.main_window.api, close_test);

        while (!iris_window_should_close(&engine.main_window))
        {
                iris_window_swap(&engine.main_window);
                iris_engine_poll_events(&engine);
        }

        iris_engine_close(&engine);

        return EXIT_SUCCESS;
}
