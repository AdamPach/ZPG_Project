#include "ScalePart.h"

ScalePart::ScalePart(glm::vec3 scale)
{
	this->scale = scale;
}

glm::mat4 ScalePart::GetTransformation(glm::mat4 M)
{
	return glm::scale(M, scale);
}
