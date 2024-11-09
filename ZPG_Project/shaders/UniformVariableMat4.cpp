#include "UniformVariableMat4.h"

UniformVariableMat4::UniformVariableMat4(UniformVariableSubject<glm::mat4>* subject, GLint uniform_location)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	this->uniform_location = uniform_location;

	Update();
}

UniformVariableMat4::~UniformVariableMat4()
{
	subject->Unsubcribe(this);
}

void UniformVariableMat4::Update()
{
	value = subject->GetValue();
}

void UniformVariableMat4::Use()
{
	glUniformMatrix4fv(uniform_location, 1, GL_FALSE, &value[0][0]);
}
