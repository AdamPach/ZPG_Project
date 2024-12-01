#version 330

in vec3 FragPos;
in vec3 Normal;

struct Material {
    vec3 color;
    float specular;
    float ambiente;
    float diffuse;
};

uniform Material material;

out vec4 frag_colour;

void main () {

    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec4 ambient = material.ambiente * vec4(lightColor, 1.0);

    frag_colour = ambient * vec4(material.color, 1);
};