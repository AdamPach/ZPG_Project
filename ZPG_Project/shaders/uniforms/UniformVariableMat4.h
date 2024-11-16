#pragma once

#include "UniformVarianble.h"

class UniformVariableMat4 : public UniformVariable
{
public:
	UniformVariableMat4(UniformVariableSubject<glm::mat4>* subject, GLuint shader_program, GLint uniform_location);
	~UniformVariableMat4();
	void Update() override;
private:
	UniformVariableSubject<glm::mat4>* subject;
};