#version 330

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightPosition;
uniform vec3 lightColor;

out vec4 frag_colour;

void main () {
    vec3 norm = normalize(Normal);

     vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

     vec3 lightDir = normalize(lightPosition - FragPos);
     float diff = max(dot(norm, lightDir), 0.0);
     vec4 diffuse = diff * vec4(lightColor, 1.0);

     frag_colour = (diffuse + ambient) * vec4( 0.41, 0.96, 0.25, 1.0);
};