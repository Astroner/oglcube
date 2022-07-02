#include "GL/glew.h"

#if !defined(SHADER)
#define SHADER

typedef struct {
    GLuint (*createShader)(GLenum type, char *filename);
} ShaderModuleType;

ShaderModuleType ShaderModule;

#endif // SHADER
