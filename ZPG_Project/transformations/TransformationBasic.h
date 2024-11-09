#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class TransformationBasic
{
public:
	virtual glm::mat4 GetMatrix();
	virtual bool IsDynamic() = 0;
protected:
	glm::mat4 transformationMatrix;
};

