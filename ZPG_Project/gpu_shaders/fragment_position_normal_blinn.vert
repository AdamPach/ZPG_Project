#version 330
#define MAX_LIGHTS 100

in vec3 FragPos;
in vec3 Normal;

struct Light {
	vec3 lightPosition;
};

struct Material {
    vec3 color;
    float specular;
    float ambiente;
    float diffuse;
};

uniform Light lights[MAX_LIGHTS];
uniform int lightsCount;
uniform vec3 cameraPosition;
uniform Material material;

out vec4 frag_colour;

void main () {

    vec3 lightColor = vec3(0.5, 0.5, 0.5);

    vec4 ambient = material.ambiente * vec4(lightColor, 1.0);
    vec3 norm = normalize(Normal);

    vec4 result = vec4(0.0);

    for(int i = 0; i < lightsCount; i++) 
    {
        vec3 lightDir = normalize(lights[i].lightPosition - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec4 diffuse = material.diffuse * diff * vec4(lightColor, 1.0);

        vec3 viewDir = normalize(cameraPosition - FragPos);
        vec3 halfWayDir = normalize(lightDir + viewDir);
        float spec = pow(max(dot(norm, halfWayDir), 0.0), 16);
        vec4 specular = material.specular * spec * vec4(lightColor, 1.0);

        result += (diffuse + specular);
		
	}

    frag_colour = (result + ambient) * vec4(material.color, 1);
};