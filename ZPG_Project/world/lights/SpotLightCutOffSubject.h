#pragma once

#include <glm/glm.hpp>
#include "../../abstraction/UnifromVariableSubject.h"

class SpotLightCutOffSubject : public TypedDataProviderSubject<float>
{
public:
	SpotLightCutOffSubject();
	virtual float GetValue() override;
	void SetValue(float value);
private:
	float value;
};