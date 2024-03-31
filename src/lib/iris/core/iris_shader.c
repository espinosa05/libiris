#include <iris/core/iris_shader.h>
#include <iris/core/gfx.h>

#include <string.h> /* memset */

/* static function declaration start */
/* pretty wrapper to hide the abomination that is the 'glShaderSource' function */
static void bind_shader_src_to_id(GLuint id, const char *src_ptr);
static void compile_shader(GLuint id);
/* static function declaraion end */

Iris_Status iris_shader_compile_and_link(Iris_Shader *shader,
                const char *fragment_source, const char *vertex_source)
{
        GLuint fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
        GLuint vertex_id = glCreateShader(GL_VERTEX_SHADER);

        shader->fragment_source = strdup(fragment_source);
        shader->vertex_source = strdup(vertex_source);

        bind_shader_src_to_id(fragment_id, shader->fragment_source);
        bind_shader_src_to_id(vertex_id, shader->vertex_source);

        compile_shader(vertex_id);
        compile_shader(fragment_id);

        shader->id = glCreateProgram();

        glAttachShader(shader->id, fragment_id);
        glAttachShader(shader->id, vertex_id);

        glLinkProgram(shader->id);

        glDeleteShader(fragment_id);
        glDeleteShader(vertex_id);

        return IRIS_ENGINE_SUCCESS;
}

Iris_Status iris_shader_use(Iris_Shader *shader)
{
        glUseProgram(shader->id);
}

Iris_Status iris_shader_close(Iris_Shader *shader)
{
        glDeleteProgram(shader->id);
        free(shader->fragment_source);
        free(shader->vertex_source);
        memset(shader, 0, sizeof(*shader));
}

static void bind_shader_src_to_id(GLuint id, const char *src_ptr)
{
        glShaderSource(id, 1, &src_ptr, NULL);
}

static void compile_shader(GLuint id)
{
        glCompileShader(id);
}
