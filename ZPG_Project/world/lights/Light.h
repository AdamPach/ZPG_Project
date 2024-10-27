#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "LightPositionSubject.h"
#include "LightColorSubject.h"


class Light
{
public:
	Light();

	void SetPosition(float x, float y, float z);
	void SetColor(float r, float g, float b);

	UniformVariableSubject<glm::vec3>* GetPositionSubject();
	UniformVariableSubject<glm::vec3>* GetColorSubject();
private:
	LightPositionSubject positionSubject;
	LightColorSubject colorSubject;
};