#include "UniformVariableInt.h"

UniformVariableInt::UniformVariableInt(UniformVariableSubject<int>* subject, GLint uniform_location)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	this->uniform_location = uniform_location;

	Update();
}

UniformVariableInt::~UniformVariableInt()
{
	subject->Unsubcribe(this);
}

void UniformVariableInt::Update()
{
	value = subject->GetValue();
}

void UniformVariableInt::Use()
{
	glUniform1i(uniform_location, value);
}
