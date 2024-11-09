#include "CameraViewSubject.h"

CameraViewSubject::CameraViewSubject()
{
	value = glm::mat4(1.0f);
}

glm::mat4 CameraViewSubject::GetValue()
{
    return value;
}

void CameraViewSubject::SetValue(glm::mat4 value)
{
	this->value = value;
	Notify();
}
