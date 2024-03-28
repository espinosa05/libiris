#include <stdio.h>
#include <stdlib.h>
#include <iris/iris.h>

int main(int argc, char **argv)
{
        Iris_Engine engine;
        iris_engine_init(&engine, "window_creation");

        while (!engine.should_close)
        {
                iris_engine_handle_event_queue(&engine);
                iris_engine_render_context(&engine);
        }

        iris_engine_close(&engine);

        return EXIT_SUCCESS;
}
