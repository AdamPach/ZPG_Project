#pragma once

#include "TransformationBasic.h"

class Rotation : public TransformationBasic
{
public:
	Rotation(float angle, glm::vec3 axis);
	glm::mat4 GetTransformation(glm::mat4 M);
private:
	float angle;
	glm::vec3 axis;
};

