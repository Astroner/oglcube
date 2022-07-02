#version 110

uniform vec3 size;
uniform vec3 shift;
uniform float time;

attribute vec3 position;

varying vec2 uv;

void main() {    
    mat3 rotation = mat3(
        vec3( cos(time),  sin(time),  0.0),
        vec3(-sin(time),  cos(time),  0.0),
        vec3(        0.0,         0.0,  1.0)
    );
    mat3 xzRotation = mat3(
        vec3(.7, 0.0, .7),
        vec3(0.0, 1.0, 0.0),
        vec3(-0.5, 0.0, .5)
    );

    gl_Position = vec4((position / size - 1.0 + shift * 2.0 / size) * xzRotation * rotation, 1.0);
    uv = position.xy;
}