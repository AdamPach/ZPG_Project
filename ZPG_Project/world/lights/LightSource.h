#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightSource : public UniformVariableSubject<glm::vec3>
{
public:
	LightSource();

	void SetPosition(float x, float y, float z);

	glm::vec3 GetValue() override;
private:
	float x, y, z;
};