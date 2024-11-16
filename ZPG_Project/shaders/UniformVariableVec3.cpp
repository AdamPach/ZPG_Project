#include "UniformVariableVec3.h"

UniformVariableVec3::UniformVariableVec3(UniformVariableSubject<glm::vec3>* subject, GLuint shader_program, GLint uniform_location) : UniformVariable(shader_program, uniform_location)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	Update();
}

UniformVariableVec3::~UniformVariableVec3()
{
	subject->Unsubcribe(this);
}

void UniformVariableVec3::Update()
{
	auto value = subject->GetValue();

	glProgramUniform3f(shader_program, uniform_location, value.x, value.y, value.z);
}