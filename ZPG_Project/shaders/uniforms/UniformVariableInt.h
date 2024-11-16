#pragma once

#include "UniformVarianble.h"

class UniformVariableInt : public UniformVariable
{
public:
	UniformVariableInt(UniformVariableSubject<int>* subject, GLuint shader_program, GLint uniform_location);
	~UniformVariableInt();
	void Update() override;
private:
	UniformVariableSubject<int>* subject;
};