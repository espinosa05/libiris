#include <stdio.h>
#include <stdlib.h>
#include <iris/iris.h>


int main(int argc, char **argv)
{
        Iris_Engine engine;
        init_iris_engine(&engine);
        init_iris_window(&engine->main_window, "iris test window", IRIS_WINDOW_FULLSCREEN, 0, 0,);


        close_iris_window(&engine->main_window);
        close_iris_engine(&engine);
        return EXIT_SUCCESS;
}
