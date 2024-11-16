#include "UniformVariableInt.h"

UniformVariableInt::UniformVariableInt(UniformVariableSubject<int>* subject, GLuint shader_program, GLint uniform_location) : UniformVariable(shader_program, uniform_location)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	Update();
}

UniformVariableInt::~UniformVariableInt()
{
	subject->Unsubcribe(this);
}

void UniformVariableInt::Update()
{
	auto value = subject->GetValue();
	glProgramUniform1i(shader_program, uniform_location, value);
}
