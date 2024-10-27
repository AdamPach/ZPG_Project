#include "LightPositionSubject.h"

LightPositionSubject::LightPositionSubject()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void LightPositionSubject::SetValue(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
	Notify();
}

glm::vec3 LightPositionSubject::GetValue()
{
    return position;
}
