#include "CameraPositionSubject.h"

CameraPositionSubject::CameraPositionSubject()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void CameraPositionSubject::SetValue(glm::vec3 position)
{
	this->position = glm::vec3(position);
	Notify();
}

glm::vec3 CameraPositionSubject::GetValue()
{
	return position;
}
