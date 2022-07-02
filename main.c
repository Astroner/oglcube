#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#ifdef __APPLE__
#   include<GLUT/glut.h>
#else
#   include<GL/glut.h>
#endif

#include "cube/cube.h"
#include "utils/utils.h"
#include "shader/shader.h"
#include "program/program.h"

#define WIDTH windowSize.width
#define HEIGHT windowSize.height
#define DEPTH windowSize.depth

struct {
    GLuint width;
    GLuint height;
    GLuint depth;
} windowSize = { 1280, 720, 720 };

struct {
    GLfloat time;
    struct {
        Cube geom;
        GLuint vertices, elements;
        GLuint program;
        struct {
            GLint position;
        } attrs;
        struct {
            GLint size;
            GLint shift;
            GLint time;
        } unifs;
    } cube;
} resources;

void tick(){
    int milliseconds = glutGet(GLUT_ELAPSED_TIME);
    resources.time = milliseconds * 0.001f;
    glutPostRedisplay();
}

void render(){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(resources.cube.program);

    glUniform1f(resources.cube.unifs.time, resources.time);
    glUniform3f(resources.cube.unifs.size, WIDTH, HEIGHT, DEPTH);
    glUniform3f(resources.cube.unifs.shift, resources.cube.geom.position.x, resources.cube.geom.position.y, resources.cube.geom.position.z);

    glBindBuffer(GL_ARRAY_BUFFER, resources.cube.vertices);
    glVertexAttribPointer(
        resources.cube.attrs.position,
        resources.cube.geom.perEAttributes,
        GL_FLOAT,
        GL_FALSE,
        sizeof(GLfloat) * resources.cube.geom.perEAttributes,
        (void*)0
    );

    glEnableVertexAttribArray(resources.cube.attrs.position);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, resources.cube.elements);
    glDrawElements(
        GL_TRIANGLE_STRIP,
        resources.cube.geom.elCount,
        GL_UNSIGNED_SHORT,
        (void*)0
    );
    glDisableVertexAttribArray(resources.cube.attrs.position);
    glutSwapBuffers();
}

void resize(int width, int height) {
    WIDTH = width;
    HEIGHT = height;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Cube");
    glutDisplayFunc(render);
    glutIdleFunc(tick);
    glutReshapeFunc(resize);

    glewInit();
    if (!GLEW_VERSION_2_0) {
        fprintf(stderr, "OpenGL 2.0 not available\n");
        return 1;
    }

    Cube cube;

    CubeModule.initCube(&cube, 100.0f);
    CubeModule.setPosition(&cube, 640.0f, 360.0f, 0.0f);

    GLuint gBuffers[2];

    glGenBuffers(2, gBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, gBuffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube.vertexes), cube.vertexes, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gBuffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube.elements), cube.elements, GL_STATIC_DRAW);

    GLuint shaders[2] = { 
        ShaderModule.createShader(GL_VERTEX_SHADER, "shaders/vertex.glsl"),
        ShaderModule.createShader(GL_FRAGMENT_SHADER, "shaders/fragment.glsl")
    };

    GLuint cubeProgram = ProgramModule.createProgram(
        2,
        shaders
    );

    resources.cube.geom = cube;

    resources.cube.program = cubeProgram;
    resources.cube.vertices = gBuffers[0];
    resources.cube.elements = gBuffers[1];

    resources.cube.unifs.size = glGetUniformLocation(cubeProgram, "size");
    resources.cube.unifs.shift = glGetUniformLocation(cubeProgram, "shift");
    resources.cube.unifs.time = glGetUniformLocation(cubeProgram, "time");

    resources.cube.attrs.position = glGetAttribLocation(cubeProgram, "position");

    glutMainLoop();
    return 0;
}