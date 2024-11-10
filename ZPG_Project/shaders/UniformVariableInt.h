#pragma once

#include "UniformVarianble.h"

class UniformVariableInt : public UniformVariable
{
public:
	UniformVariableInt(UniformVariableSubject<int>* subject, GLint uniform_location);
	~UniformVariableInt();
	void Update() override;
	void Use() override;
private:
	int value;
	UniformVariableSubject<int>* subject;
};