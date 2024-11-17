#include "LightColorSubject.h"

LightColorSubject::LightColorSubject()
{
	value = glm::vec3(1.0f, 1.0f, 1.0f);
}

glm::vec3 LightColorSubject::GetValue()
{
	return value;
}

void LightColorSubject::SetValue(glm::vec3 value)
{
	this->value = glm::vec3(value);
	Notify();
}
