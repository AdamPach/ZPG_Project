#include "LightPositionSubject.h"

LightPositionSubject::LightPositionSubject()
{
	value = glm::vec3(0, 0, 0);
}

glm::vec3 LightPositionSubject::GetValue()
{
	return value;
}

void LightPositionSubject::SetValue(glm::vec3 value)
{
	this->value = value;
	Notify();
}
