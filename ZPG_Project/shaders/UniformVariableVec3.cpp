#include "UniformVariableVec3.h"

UniformVariableVec3::UniformVariableVec3(UniformVariableSubject<glm::vec3>* subject, GLuint shader_program_id, const char* variable_name)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	uniform_location = glGetUniformLocation(shader_program_id, variable_name);

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