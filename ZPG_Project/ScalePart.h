#pragma once

#include "TransformationPart.h"

class ScalePart : public TransformationPart
{
public:
	ScalePart(glm::vec3 scale);
	glm::mat4 GetTransformation(glm::mat4 M);
private:
	glm::vec3 scale;
};

