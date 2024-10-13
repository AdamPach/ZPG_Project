#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class TransformationPart
{
public:
	virtual glm::mat4 GetTransformation(glm::mat4 M) = 0;
};

