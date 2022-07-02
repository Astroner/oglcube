#include "GL/glew.h"

#if !defined(SHADER)
#define SHADER

static GLuint createShader(GLenum type, char* filename);

typedef struct {
    GLuint (*createShader)(GLenum type, char *filename);
} ShaderModuleType;

ShaderModuleType ShaderModule = { createShader };

#endif // SHADER
