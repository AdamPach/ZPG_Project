#pragma once

#include "UniformVarianble.h"

class UniformVariableMat4 : public UniformVariable
{
public:
	UniformVariableMat4(TypedDataProviderSubject<glm::mat4>* subject, GLuint shader_program, GLint uniform_location);
	~UniformVariableMat4();
	void Update() override;
private:
	TypedDataProviderSubject<glm::mat4>* subject;
};