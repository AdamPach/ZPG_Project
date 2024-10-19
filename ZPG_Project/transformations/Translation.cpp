#include "Translation.h"

Translation::Translation(glm::vec3 direction)
{
	this->direction = direction;
}

glm::mat4 Translation::GetTransformation(glm::mat4 M)
{
	return glm::translate(M, direction);
}
