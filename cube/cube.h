#include <GL/glew.h>

#if !defined(CUBE)
#define CUBE

typedef struct Cube {
    GLfloat vertexes[24];
    GLushort perEAttributes;

    GLushort *elements;
    GLushort elCount;

    struct {
        GLfloat x;
        GLfloat y;
        GLfloat z;
    } position;
} Cube;

static void initCube(Cube *self, GLfloat width);
static void setPosition(Cube *self, GLfloat x, GLfloat y);

typedef struct CubeModuleType {
    void(*initCube)(Cube* self, GLfloat width);
    void(*setPosition)(Cube* self, GLfloat x, GLfloat y, GLfloat z);
} CubeModuleType;

CubeModuleType CubeModule = { initCube, setPosition };

#endif // CUBE
