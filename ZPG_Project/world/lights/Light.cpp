#include "Light.h"

Light::Light()
{
	positionSubject = LightPositionSubject();
	colorSubject = LightColorSubject();
}

void Light::SetPosition(float x, float y, float z)
{
	positionSubject.SetValue(x, y, z);
}

void Light::SetColor(float r, float g, float b)
{
	colorSubject.SetValue(r, g, b);
}

UniformVariableSubject<glm::vec3>* Light::GetPositionSubject()
{
	return &positionSubject;
}

UniformVariableSubject<glm::vec3>* Light::GetColorSubject()
{
	return &colorSubject;
}
