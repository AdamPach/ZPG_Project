#version 330
#define MAX_LIGHTS 100

in vec3 FragPos;
in vec3 Normal;

struct Light {
    int lightType;
	vec3 lightPosition;
    vec3 lightColor;
    //Spotlight only
    vec3 lightDirection;
    float cutOff;
    float outerCutOff;
};

uniform Light lights[MAX_LIGHTS];
uniform int lightsCount;
uniform vec3 cameraPosition;
uniform vec3 materialColor;

out vec4 frag_colour;

float calculateAttenuation(vec3 lightPos)
{
	float distance = length(lightPos - FragPos);
	return 1.0 / (0.3 + 0.3 * distance + 0.3 * distance * distance);
}

vec4 calculatePointLight(Light light)
{
    vec3 norm = normalize(Normal);

    vec3 lightDir = normalize(light.lightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * vec4(light.lightColor, 1.0);

    vec3 viewDir = normalize(cameraPosition - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(reflectDir, viewDir), 0.0), 16);

    float specularStrength = 1;

    vec4 specular = specularStrength * spec * vec4(light.lightColor, 1.0);

    return ((diffuse + specular) * calculateAttenuation(light.lightPosition));
}

vec4 calculateSpotLight(Light light)
{
    vec3 norm = normalize(Normal);

    vec3 lightDir = normalize(light.lightPosition - FragPos);

    float theta = dot(lightDir, normalize(-light.lightDirection));

    if(theta > light.cutOff)
	{
		float diff = max(dot(norm, lightDir), 0.0);
		vec4 diffuse = diff * vec4(light.lightColor, 1.0);

		vec3 viewDir = normalize(cameraPosition - FragPos);
		vec3 reflectDir = reflect(-lightDir, norm);
		float spec = pow(max(dot(reflectDir, viewDir), 0.0), 16);

		float specularStrength = 1;

		vec4 specular = specularStrength * spec * vec4(light.lightColor, 1.0);

		return ((diffuse + specular) * calculateAttenuation(light.lightPosition));
	}
    
    return vec4(0.0);
}

void main () {

    float ambientStrength = 0.1;
    vec3 lightColor = vec3(0.5, 0.5, 0.5);

    vec4 ambient = ambientStrength * vec4(lightColor, 1.0);

    vec4 result = vec4(0.0);

    for(int i = 0; i < lightsCount; i++)
    {
        if(lights[i].lightType == 1)
		{
			result += calculatePointLight(lights[i]);
		}
        else if(lights[i].lightType == 2)
		{
			result += calculateSpotLight(lights[i]);
		}
    }

    frag_colour = (ambient + result) * vec4(materialColor, 1.0);
};