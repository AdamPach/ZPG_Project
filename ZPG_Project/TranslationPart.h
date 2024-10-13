#pragma once

#include "TransformationPart.h"

class TranslationPart : public TransformationPart
{
public:
	TranslationPart(glm::vec3 direction);
	glm::mat4 GetTransformation(glm::mat4 M);
private:
	glm::vec3 direction;
};

