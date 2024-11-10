#version 330
#define MAX_LIGHTS 1000

in vec3 FragPos;
in vec3 Normal;

struct Light {
	vec3 lightPosition;
};

uniform Light lights[MAX_LIGHTS];
uniform int lightsCount;
uniform vec3 cameraPosition;
uniform vec3 materialColor;

out vec4 frag_colour;

void main () {

    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);

    vec4 ambient = ambientStrength * vec4(lightColor, 1.0);
    vec3 norm = normalize(Normal);
    float specularStrength = 1;

    vec4 result = vec4(0.0);

    for(int i = 0; i < lightsCount; i++)
    {
        vec3 lightDir = normalize(lights[i].lightPosition - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec4 diffuse = diff * vec4(lightColor, 1.0);

        vec3 viewDir = normalize(cameraPosition - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(reflectDir, viewDir), 0.0), 16);
        vec4 specular = specularStrength * spec * vec4(lightColor, 1.0);

        result += (diffuse + specular);
    }

    frag_colour = (ambient + result) * vec4(materialColor, 1.0);
};