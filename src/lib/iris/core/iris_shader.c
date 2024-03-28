#include <iris/core/iris_shader.h>
#include <iris/core/gfx.h>

/* static function declaration start */
/* pretty wrapper to hide the abomination that is the 'glShaderSource' function */
static void bind_shader_src_to_id(GLuint id, char **src_ptr);
/* static function declaraion end */

Iris_Status iris_shader_compile_and_link(Iris_Shader *shader,
                char *fragment_source, char *vertex_source)
{
        GLuint vertex_id = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment_id = glCreateShader(GL_FRAGMENT_SHADER);

        shader->fragment_source = fragment_source;
        shader->vertex_source = vertex_source;

        bind_shader_src_to_id(fragment_id, &shader->fragment_source);
        bind_shader_src_to_id(vertex_id, &shader->vertex_source);

        glCompileShader(vertex_id);
        glCompileShader(fragment_id);

        shader->id = glCreateProgram();

        glAttachShader(shader->id, vertex_id);
        glAttachShader(shader->id, fragment_id);

        glLinkProgram(shader->id);

        glDeleteShader(fragment_id);
        glDeleteShader(vertex_id);

        return IRIS_ENGINE_SUCCESS;
}

Iris_Status iris_shader_use(Iris_Shader *shader)
{
        glUseProgram(shader->id);
}

static void bind_shader_src_to_id(GLuint id, char **src_ptr)
{
        glShaderSource(id, 1, src_ptr, NULL);
}
