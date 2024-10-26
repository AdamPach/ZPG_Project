#version 330

in vec3 FragPos;
in vec3 Normal;

out vec4 frag_colour;

void main () {
    vec3 norm = normalize(Normal);

     vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);
     vec3 lightPosition = vec3(0, 0, -1);

     vec3 lightDir = normalize(lightPosition - FragPos);
     float diff = max(dot(norm, lightDir), 0.0);
     vec4 diffuse = diff * vec4( 0.5, 0.647, 0.812, 1.0);

     frag_colour = (diffuse + ambient) * vec4( 0.41, 0.96, 0.25, 1.0);
};