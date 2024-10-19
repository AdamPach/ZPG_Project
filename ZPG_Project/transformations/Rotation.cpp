#include "Rotation.h"

Rotation::Rotation(float angle, glm::vec3 axis)
{
	this->angle = angle;
	this->axis = axis;
}

glm::mat4 Rotation::GetTransformation(glm::mat4 M)
{
	return glm::rotate(M, glm::radians(angle), axis);
}
