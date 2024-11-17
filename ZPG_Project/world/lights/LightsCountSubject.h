#pragma once

#include <glm/glm.hpp>
#include "../../abstraction/UnifromVariableSubject.h"

class LightsCountSubject : public TypedDataProviderSubject<int>
{
public:
	LightsCountSubject();
	virtual int GetValue() override;
	void SetValue(int value);
};