#version 330

layout(location=0) in vec3 vp;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 TexCoords;

void main () {
     vec4 pos = modelMatrix * vec4(vp, 1.0);

     gl_Position = projectionMatrix * viewMatrix * pos;

     TexCoords = vp;
};