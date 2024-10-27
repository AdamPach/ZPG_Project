#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightColorSubject : public UniformVariableSubject<glm::vec3>
{
public:
	LightColorSubject();
	void SetValue(float r, float g, float b);

	glm::vec3 GetValue() override;
private:
	glm::vec3 color;
};