#version 330

layout(location=0) in vec3 vp;
layout(location=1) in vec3 normal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 FragPos;
out vec3 Normal;

void main () {
     gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (vp, 1.0);
     vec4 pos = modelMatrix * vec4(vp, 1.0);
     FragPos = vec3(pos.xyz / pos.w);
     Normal = mat3(transpose(inverse(modelMatrix))) * normal;
};