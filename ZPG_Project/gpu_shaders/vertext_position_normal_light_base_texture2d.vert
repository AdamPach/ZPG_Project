#version 330

layout(location=0) in vec3 vp;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 uv;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

void main () {
     vec4 pos = modelMatrix * vec4(vp, 1.0);

     gl_Position = projectionMatrix * viewMatrix * pos;

     FragPos = vec3(pos.xyz / pos.w);
     Normal = mat3(transpose(inverse(modelMatrix))) * normal;
     TexCoords = uv;
};