#include "LightPositionSubject.h"

LightPositionSubject::LightPositionSubject()
{
	value = glm::vec3(0.0f, 0.0f, 0.0f);
}

void LightPositionSubject::SetValue(glm::vec3 value)
{
	this->value = glm::vec3(value);
	Notify();
}

glm::vec3 LightPositionSubject::GetValue()
{
    return value;
}
