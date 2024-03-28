#include <iris/iris.h>
#include <iris/core/gfx.h>

Iris_Status iris_engine_init(Iris_Engine *engine, char *instance_id)
{
        if (!glfwInit())
        {
                printf("glfw could not init\n");
                return IRIS_ENGINE_FAILED_TO_START_GLFW;
        }

        if (!instance_id)
                instance_id = "generic_iris_instance";

        iris_window_init(&engine->main_window, instance_id, IRIS_WINDOW_MAKE_FULLSCREEN, 0, 0);
        engine->should_close = false;

        return IRIS_ENGINE_SUCCESS;
}

Iris_Status iris_engine_close(Iris_Engine *engine)
{
        TODO("impl");

        return IRIS_ENGINE_SUCCESS;
}
