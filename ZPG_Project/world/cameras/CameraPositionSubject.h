#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class CameraPositionSubject : public UniformVariableSubject<glm::vec3>
{
public:
	CameraPositionSubject();
	void SetValue(glm::vec3 position);

	glm::vec3 GetValue() override;
private:
	glm::vec3 position;
};