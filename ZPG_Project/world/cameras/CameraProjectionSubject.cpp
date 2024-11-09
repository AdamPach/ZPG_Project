#include "CameraProjectionSubject.h"

CameraProjectionSubject::CameraProjectionSubject()
{
	value = glm::mat4(1.0f);
}

void CameraProjectionSubject::SetValue(glm::mat4 value)
{
	this->value = value;
	Notify();
}

glm::mat4 CameraProjectionSubject::GetValue()
{
    return value;
}
