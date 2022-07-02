#include "cube.h"
#include <stdlib.h>

static GLfloat positions[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,
     1.0f,  1.0f, 0.0f
    -1.0f, -1.0f, 1.0f,
     1.0f, -1.0f, 1.0f,
    -1.0f,  1.0f, 1.0f,
     1.0f,  1.0f, 1.0f
};

static GLushort elements[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

static void initCube(Cube *self, GLfloat width) {
    GLfloat half = width / 2.0;

    self->position.x = 0;
    self->position.y = 0;

    self->elements = elements;
    self->elCount = 8;
    self->perEAttributes = 3;

    for (int i = 0; i < self->elCount * self->perEAttributes; i += self->perEAttributes) {
        self->vertexes[i] = positions[i] * half;
        self->vertexes[i + 1] = positions[i + 1] * half;
        self->vertexes[i + 2] = positions[i + 2] * width;
    }
    
}

static void setPosition(Cube *self, GLfloat x, GLfloat y) {
    self->position.x = x;
    self->position.y = y;
}