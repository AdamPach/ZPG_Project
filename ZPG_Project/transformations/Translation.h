#pragma once

#include "TransformationBasic.h"

class Translation : public TransformationBasic
{
public:
	Translation(glm::vec3 direction);
	glm::mat4 GetTransformation(glm::mat4 M);
private:
	glm::vec3 direction;
};

