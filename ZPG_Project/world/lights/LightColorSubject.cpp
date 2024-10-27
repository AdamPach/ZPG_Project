#include "LightColorSubject.h"

LightColorSubject::LightColorSubject()
{
	color = glm::vec3(0.0f, 0.0f, 0.0f);
}

void LightColorSubject::SetValue(float r, float g, float b)
{
	color = glm::vec3(r, g, b);
	Notify();
}

glm::vec3 LightColorSubject::GetValue()
{
	return color;
}
