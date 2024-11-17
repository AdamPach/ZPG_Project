#pragma once

#include "UniformVarianble.h"

class UniformVariableFloat : public UniformVariable
{
public:
	UniformVariableFloat(TypedDataProviderSubject<float>* subject, GLuint shader_program, GLint uniform_location);
	~UniformVariableFloat();
	void Update() override;
private:
	TypedDataProviderSubject<float>* subject;
};