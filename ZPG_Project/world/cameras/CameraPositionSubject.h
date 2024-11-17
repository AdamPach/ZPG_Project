#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class CameraPositionSubject : public TypedDataProviderSubject<glm::vec3>
{
public:
	CameraPositionSubject();

	glm::vec3 GetValue() override;
	void SetValue(glm::vec3 value);
};