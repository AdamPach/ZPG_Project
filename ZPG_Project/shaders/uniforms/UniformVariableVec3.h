#pragma once

#include <glm/glm.hpp>

#include "UniformVarianble.h"
#include <GL/glew.h>

class UniformVariableVec3 : public UniformVariable
{
public:
	UniformVariableVec3(TypedDataProviderSubject<glm::vec3>* subject, GLuint shader_program, GLint uniform_location);
	~UniformVariableVec3();
	void Update() override;
private:
	TypedDataProviderSubject<glm::vec3>* subject;
};