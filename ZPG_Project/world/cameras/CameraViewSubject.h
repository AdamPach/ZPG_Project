#pragma once

#include <glm/glm.hpp>
#include "../../abstraction/UnifromVariableSubject.h"

class CameraViewSubject : public TypedDataProviderSubject<glm::mat4>
{
public:
	CameraViewSubject();
	glm::mat4 GetValue() override;
	void SetValue(glm::mat4 value);
};