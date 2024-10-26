#version 330

in vec3 FragPos;
out vec4 frag_colour;

void main () {
     vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);
     vec3 lightPosition = vec3(10.0,10.0,10.0);
     vec3 lightDir = normalize(lightPosition - FragPos);
     float diff = max(dot(lightDir, normalize(FragPos)), 0.0);
     vec4 diffuse = diff * vec4( 0.5, 0.647, 0.812, 1.0);
     frag_colour = ambient + diffuse;
};