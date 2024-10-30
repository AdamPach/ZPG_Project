#version 330

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightColor;

out vec4 frag_colour;

void main () {

    float ambientStrength = 0.3;
    vec4 ambient = ambientStrength * vec4(lightColor, 1.0);

    vec4 objectColor = vec4(0.385, 0.647, 0.812, 1.0);

    frag_colour = ambient * objectColor;
};