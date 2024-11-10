#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightPositionSubject : public UniformVariableSubject<glm::vec3>
{
public:
	LightPositionSubject();
	virtual glm::vec3 GetValue() override;
	virtual void SetValue(glm::vec3 value) override;
private:
	glm::vec3 value;
};