#include <GL/glew.h>

#if !defined(PROGRAM)
#define PROGRAM

typedef struct {
    GLuint (*createProgram)(GLuint size, GLuint* shaders);
} ProgramModuleType;

ProgramModuleType ProgramModule;

#endif // PROGRAM
