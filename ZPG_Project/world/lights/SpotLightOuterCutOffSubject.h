#pragma once

#include <glm/glm.hpp>
#include "../../abstraction/UnifromVariableSubject.h"

class SpotLightOuterCutOffSubject : public TypedDataProviderSubject<float>
{
public:
	SpotLightOuterCutOffSubject();
	virtual float GetValue() override;
	void SetValue(float value);
private:
	float value;
};