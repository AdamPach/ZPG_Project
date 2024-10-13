#include "TranslationPart.h"

TranslationPart::TranslationPart(glm::vec3 direction)
{
	this->direction = direction;
}

glm::mat4 TranslationPart::GetTransformation(glm::mat4 M)
{
	return glm::translate(M, direction);
}
