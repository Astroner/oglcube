#include <GL/glew.h>

#if !defined(PROGRAM)
#define PROGRAM

static GLuint createProgram(GLuint size, GLuint* shaders);

typedef struct {
    GLuint (*createProgram)(GLuint size, GLuint* shaders);
} ProgramModuleType;

ProgramModuleType ProgramModule = { createProgram };

#endif // PROGRAM
