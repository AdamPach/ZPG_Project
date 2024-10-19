#include "Scale.h"

Scale::Scale(glm::vec3 scale)
{
	this->scale = scale;
}

glm::mat4 Scale::GetTransformation(glm::mat4 M)
{
	return glm::scale(M, scale);
}
