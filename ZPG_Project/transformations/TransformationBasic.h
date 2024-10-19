#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class TransformationBasic
{
public:
	virtual glm::mat4 GetMatrix();
protected:
	glm::mat4 transformationMatrix;
};

