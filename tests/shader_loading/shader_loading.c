#include <stdio.h>
#include <stdlib.h>
#include <iris/iris.h>

#include <assert.h>


int main(int argc, char **argv)
{
        Iris_Engine engine;
        struct iris_settings settings = {
                .width = 1200,
                .height = 720,
                .window_flags = IRIS_ENGINE_DEFAULT_WINDOW_FLAGS,
                .instance_id = "iris shader testing",
        };

        iris_engine_init(&engine, &settings);

        Iris_Shader shader;
        const char fsrc[] =
        "#version 330 core\n"
        "layout (location = 0) in vec3 inPosition;\n"
        "\n"
        "void main() {\n"
        "        gl_Position = inPosition;\n"
        "}";

        const char vsrc[] =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "        color = vec4(0.0, 0.2, 0.1, 1.0);\n"
        "}";

        iris_shader_compile_and_link(&shader, fsrc, vsrc);
        iris_engine_start_renderer(&engine);

        while (!engine.should_close)
        {
                iris_engine_poll_events(&engine);
                iris_engine_render_context(&engine);
        }

        iris_shader_close(&shader);

        return EXIT_SUCCESS;
}

