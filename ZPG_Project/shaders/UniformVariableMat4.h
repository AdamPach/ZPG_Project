#pragma once

#include "UniformVarianble.h"

class UniformVariableMat4 : public UniformVariable
{
public:
	UniformVariableMat4(UniformVariableSubject<glm::mat4>* subject, GLint uniform_location);
	~UniformVariableMat4();
	void Update() override;
	void Use() override;
private:
	glm::mat4 value;
	UniformVariableSubject<glm::mat4>* subject;
};