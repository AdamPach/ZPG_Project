#pragma once

#include "TransformationPart.h"

class RotationPart : public TransformationPart
{
public:
	RotationPart(float angle, glm::vec3 axis);
	glm::mat4 GetTransformation(glm::mat4 M);
private:
	float angle;
	glm::vec3 axis;
};

