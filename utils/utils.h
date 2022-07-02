#include <GL/glew.h>

#if !defined(UTILS)
#define UTILS

typedef struct UtilsModuleType {
    void* (*fileContent)(char *filename, GLint *length);
} UtilsModuleType;

UtilsModuleType UtilsModule;

#endif // UTILS
