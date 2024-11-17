#pragma once

#include <glm/glm.hpp>

#include "../../abstraction/UnifromVariableSubject.h"

class LightTypeSubject : public TypedDataProviderSubject<int>
{
public:
	LightTypeSubject();
	virtual int GetValue() override;
	void SetValue(int value);
private:
	int value;
};