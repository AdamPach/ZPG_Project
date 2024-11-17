#pragma once

#include <glm/glm.hpp>
#include "../../abstraction/UnifromVariableSubject.h"

class CameraFrontSubject : public TypedDataProviderSubject<glm::vec3>
{
public:
	CameraFrontSubject();
	glm::vec3 GetValue() override;
	void SetValue(glm::vec3 value);
private:
	glm::vec3 value;
};