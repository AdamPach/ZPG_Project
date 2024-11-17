#include "UniformVariableFloat.h"

UniformVariableFloat::UniformVariableFloat(TypedDataProviderSubject<float>* subject, GLuint shader_program, GLint uniform_location) : UniformVariable(shader_program, uniform_location)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	Update();
}

UniformVariableFloat::~UniformVariableFloat()
{
	subject->Unsubcribe(this);
}

void UniformVariableFloat::Update()
{
	auto value = subject->GetValue();
	glProgramUniform1f(shader_program, uniform_location, value);
}