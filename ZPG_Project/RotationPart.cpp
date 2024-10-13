#include "RotationPart.h"

RotationPart::RotationPart(float angle, glm::vec3 axis)
{
	this->angle = angle;
	this->axis = axis;
}

glm::mat4 RotationPart::GetTransformation(glm::mat4 M)
{
	return glm::rotate(M, glm::radians(angle), axis);
}
