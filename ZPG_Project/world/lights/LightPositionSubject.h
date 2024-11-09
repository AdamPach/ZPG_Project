#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightPositionSubject : public UniformVariableSubject<glm::vec3>
{
public:
	LightPositionSubject();
	void SetValue(glm::vec3 value) override;
	glm::vec3 GetValue() override;
};