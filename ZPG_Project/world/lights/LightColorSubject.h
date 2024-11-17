#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightColorSubject : public TypedDataProviderSubject<glm::vec3>
{
public:
	LightColorSubject();
	virtual glm::vec3 GetValue() override;
	void SetValue(glm::vec3 value);
private:
	glm::vec3 value;
};