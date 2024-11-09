#include "Light.h"

Light::Light()
{
	positionSubject = LightPositionSubject();
	colorSubject = LightColorSubject();
}

void Light::SetPosition(float x, float y, float z)
{
	positionSubject.SetValue(glm::vec3(x, y, z));
}

void Light::SetColor(float r, float g, float b)
{
	colorSubject.SetValue(glm::vec3(r, g, b));
}

UniformVariableSubject<glm::vec3>* Light::GetPositionSubject()
{
	return &positionSubject;
}

UniformVariableSubject<glm::vec3>* Light::GetColorSubject()
{
	return &colorSubject;
}
