#include "CameraPositionSubject.h"

CameraPositionSubject::CameraPositionSubject()
{
	value = glm::vec3(0.0f, 0.0f, 0.0f);
}

void CameraPositionSubject::SetValue(glm::vec3 value)
{
	this->value = glm::vec3(value);
	Notify();
}

glm::vec3 CameraPositionSubject::GetValue()
{
	return value;
}
