#version 330

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 cameraPosition;
uniform vec3 materialColor;

out vec4 frag_colour;

void main () {

    float ambientStrength = 0.1;
    vec4 ambient = ambientStrength * vec4(lightColor, 1.0);

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * vec4(lightColor, 1.0);

    float specularStrength = 1;
    vec3 viewDir = normalize(cameraPosition - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(reflectDir, viewDir), 0.0), 16);
    vec4 specular = specularStrength * spec * vec4(lightColor, 1.0);

    frag_colour = (diffuse + ambient + specular) * vec4(materialColor, 1.0);
};