#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightPositionSubject : public TypedDataProviderSubject<glm::vec3>
{
public:
	LightPositionSubject();
	virtual glm::vec3 GetValue() override;
	void SetValue(glm::vec3 value);
private:
	glm::vec3 value;
};