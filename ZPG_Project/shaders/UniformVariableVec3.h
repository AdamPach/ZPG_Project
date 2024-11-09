#pragma once

#include <glm/glm.hpp>

#include "UniformVarianble.h"
#include <GL/glew.h>

class UniformVariableVec3 : public UniformVariable
{
public:
	UniformVariableVec3(UniformVariableSubject<glm::vec3>* subject, GLint uniform_location);
	~UniformVariableVec3();
	void Update() override;
	void Use() override;
private:
	glm::vec3 value;
	UniformVariableSubject<glm::vec3>* subject;
};