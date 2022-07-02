#include "program.h"
#include <stdio.h>

static GLuint createProgram(GLuint size, GLuint* shaders) {
    GLuint program = glCreateProgram();
    GLint programOk;

    for (int i = 0; i < size; i++) {
        glAttachShader(program, shaders[i]);
    }

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &programOk);

    if(!programOk) {
        printf("Failed to link program");
    }

    return program;
}

ProgramModuleType ProgramModule = { createProgram };
