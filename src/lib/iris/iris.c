#include <iris/iris.h>
#include <iris/core/gfx.h>

#include <string.h>
/* static function declarations start */
static void load_generic_iris_engine_settings(struct iris_settings *settings_buff);
/* static function declarations end */

const char g_iris_engine_generic_instance_id_str[] = "generic_iris_instance";


#define STD_IRIS_SETTINGS {                                             \
        .width          = IRIS_WINDOW_WIDTH_UNDEFINED,                  \
        .height         = IRIS_WINDOW_HEIGHT_UNDEFINED,                 \
        .window_flags   = IRIS_ENGINE_DEFAULT_WINDOW_FLAGS,             \
        .instance_id    = g_iris_engine_generic_instance_id_str,        \
}

Iris_Status iris_engine_handle_input(Iris_Engine *engine)
{
        TODO("impl");
}

Iris_Status iris_engine_init(Iris_Engine *engine, struct iris_settings *settings)
{
        if (!glfwInit())
        {
                printf("glfw could not init\n");
                return IRIS_ENGINE_FAILED_TO_START_GLFW;
        }

        /* initialize settings with generic values */
        struct iris_settings curr_settings = STD_IRIS_SETTINGS;

        /* override if user passed a pointer to settings */
        if (settings)
        {
                curr_settings = *settings;
        }

        /* wait for the engine renderer to be started */
        engine->should_close = true;
        iris_window_init(&engine->main_window,
                        curr_settings.instance_id,
                        curr_settings.window_flags,
                        curr_settings.width,
                        curr_settings.height);

        return IRIS_ENGINE_SUCCESS;
}

Iris_Status iris_engine_close(Iris_Engine *engine)
{
        glfwTerminate();
        return IRIS_ENGINE_SUCCESS;
}

Iris_Status iris_engine_start_renderer(Iris_Engine *engine)
{
        iris_window_show(&engine->main_window);
        engine->should_close = false;
        return IRIS_ENGINE_SUCCESS;
}

Iris_Status iris_engine_poll_events(Iris_Engine *engine)
{
        glfwPollEvents();
        return IRIS_ENGINE_SUCCESS;
}

Iris_Status iris_engine_render_context(Iris_Engine *engine)
{
        return IRIS_ENGINE_SUCCESS;
}
