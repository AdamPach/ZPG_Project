#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightColorSubject : public UniformVariableSubject<glm::vec3>
{
public:
	LightColorSubject();
	glm::vec3 GetValue() override;
	void SetValue(glm::vec3 value) override;
};