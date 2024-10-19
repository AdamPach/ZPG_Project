#pragma once

#include "TransformationBasic.h"

class Scale : public TransformationBasic
{
public:
	Scale(glm::vec3 scale);
	glm::mat4 GetTransformation(glm::mat4 M);
private:
	glm::vec3 scale;
};

