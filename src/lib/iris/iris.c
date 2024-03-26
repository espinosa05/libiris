#include "../../include/iris/iris.h"

#include <GLFW/glfw3.h>

Iris_Status init_iris_engine(Iris_Engine *engine)
{
        TODO("impl");
        if (!glfwInit())
                return IRIS_ENGINE_FAILED_TO_START_GLFW;


        return IRIS_ENGINE_SUCCESS;
}

Iris_Status close_iris_engine(Iris_Engine *engine)
{
        TODO("impl");

        return IRIS_ENGINE_SUCCESS;
}
