#pragma once

#include <glm/glm.hpp>
#include "../../abstraction/UnifromVariableSubject.h"

class CameraProjectionSubject : public TypedDataProviderSubject<glm::mat4>
{
public:
	CameraProjectionSubject();

	void SetValue(glm::mat4 value);
	glm::mat4 GetValue() override;
};