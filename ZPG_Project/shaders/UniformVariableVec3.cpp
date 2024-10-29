#include "UniformVariableVec3.h"

UniformVariableVec3::UniformVariableVec3(UniformVariableSubject<glm::vec3>* subject, GLint uniform_location)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	this->uniform_location = uniform_location;

	Update();
}

UniformVariableVec3::~UniformVariableVec3()
{
	subject->Unsubcribe(this);
}

void UniformVariableVec3::Update()
{
	value = subject->GetValue();
}

void UniformVariableVec3::Use()
{
	glUniform3f(uniform_location, value.x, value.y, value.z);
}