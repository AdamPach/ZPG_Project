#include "UniformVariableMat4.h"

UniformVariableMat4::UniformVariableMat4(TypedDataProviderSubject<glm::mat4>* subject, GLuint shader_program, GLint uniform_location) : UniformVariable(shader_program, uniform_location)
{
	this->subject = subject;
	this->subject->Subcribe(this);

	Update();
}

UniformVariableMat4::~UniformVariableMat4()
{
	subject->Unsubcribe(this);
}

void UniformVariableMat4::Update()
{
	auto value = subject->GetValue();

	glProgramUniformMatrix4fv(shader_program, uniform_location, 1, GL_FALSE, &value[0][0]);
}
