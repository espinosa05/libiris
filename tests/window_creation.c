#include <stdio.h>
#include <stdlib.h>
#include <iris/iris.h>

#include <unistd.h>

int main(int argc, char **argv)
{
        Iris_Engine engine;
        init_iris_engine(&engine);
        init_iris_window(&engine.main_window, "iris test window", IRIS_WINDOW_MAKE_FULLSCREEN, 1200, 720);

        iris_info_log("window created");
        sleep(3);
        iris_info_log("closing application");
        sleep(1);

        close_iris_window(&engine.main_window);
        close_iris_engine(&engine);

        return EXIT_SUCCESS;
}
