#pragma once

#include <glm/glm.hpp>

class Projection
{
public:
	virtual glm::mat4 GetProjectionMatrix() = 0;
};