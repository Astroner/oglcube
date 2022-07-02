#include "shader.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

static GLuint createShader(GLenum type, char* filename) {    
    GLuint length;
    GLuint shader = glCreateShader(type);
    GLchar *source = UtilsModule.fileContent(filename, &length);

    glShaderSource(shader, 1, (GLchar**)&source, &length);
    free(source);
    glCompileShader(shader);

    GLint shaderOk;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderOk);
    if(!shaderOk) {
        fprintf(stderr, "Failed to compile vertex shader");
        glDeleteShader(shader);
    }

    return shader;
}