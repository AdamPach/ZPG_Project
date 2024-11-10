#pragma once

#include <glm/glm.hpp>
#include "../../abstraction/UnifromVariableSubject.h"

class LightsCountSubject : public UniformVariableSubject<int>
{
public:
	LightsCountSubject();
	virtual int GetValue() override;
	virtual void SetValue(int value) override;
};