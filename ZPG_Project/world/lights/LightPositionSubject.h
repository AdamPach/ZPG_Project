#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightPositionSubject : public UniformVariableSubject<glm::vec3>
{
public:
	LightPositionSubject();
	void SetValue(float x, float y, float z);

	glm::vec3 GetValue() override;
private:
	glm::vec3 position;
};