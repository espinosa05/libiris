#include <stdio.h>
#include <stdlib.h>
#include <iris/iris.h>

#include <assert.h>

#define FRAG_PATH "../resources/test_fragment_shader.glsl"
#define VERT_PATH "../resources/test_vertex_shader.glsl"


int main(int argc, char **argv)
{
        Iris_Engine engine;
        iris_engine_init(&engine, "shader loading test");

        Iris_Shader shader;
        iris_shader_compile_and_link(&shader,
                        iris_util_load_file_contents(FRAG_PATH),
                        iris_util_load_file_contents(VERT_PATH));

        while (!engine.should_close)
        {
                iris_window_swap(&engine.main_window);
        }

        return EXIT_SUCCESS;
}
