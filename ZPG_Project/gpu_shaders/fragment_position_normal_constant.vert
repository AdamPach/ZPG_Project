#version 330

in vec3 FragPos;
in vec3 Normal;

uniform vec3 materialColor;

out vec4 frag_colour;

void main () {

    float ambientStrength = 0.3;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec4 ambient = ambientStrength * vec4(lightColor, 1.0);

    frag_colour = ambient * vec4(materialColor, 1);
};