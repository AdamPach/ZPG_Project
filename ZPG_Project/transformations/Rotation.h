#pragma once

#include "TransformationBasic.h"

class Rotation : public TransformationBasic
{
public:
	Rotation(float angle, glm::vec3 axis);
};

