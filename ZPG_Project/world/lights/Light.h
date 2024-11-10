#pragma once

#include <vector>
#include <glm/glm.hpp>


class Light
{
public:
	Light();

	void SetPosition(float x, float y, float z);
	void SetColor(float r, float g, float b);

};