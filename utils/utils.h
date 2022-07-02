#include <GL/glew.h>

#if !defined(UTILS)
#define UTILS

typedef struct UtilsModuleType {
    void* (*fileContent)(char *filename, GLint *length);
} UtilsModuleType;

static void *fileContents(const char *filename, GLint *length);

UtilsModuleType UtilsModule = { fileContents };

#endif // UTILS
