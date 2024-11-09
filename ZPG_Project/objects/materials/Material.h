#pragma once

#include <glm/glm.hpp>

class Material
{
public:
	Material(glm::vec3 color);
	glm::vec3 GetColor();
private:
	glm::vec3 color;
};