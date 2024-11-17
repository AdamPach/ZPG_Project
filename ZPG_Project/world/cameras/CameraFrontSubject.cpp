#include "CameraFrontSubject.h"

CameraFrontSubject::CameraFrontSubject()
{
	value = glm::vec3(0.0f, 0.0f, -1.0f);
}

void CameraFrontSubject::SetValue(glm::vec3 value)
{
	this->value = glm::vec3(value);
	Notify();
}

glm::vec3 CameraFrontSubject::GetValue()
{
	return value;
}