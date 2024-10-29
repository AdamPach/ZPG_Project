#pragma once

#include <glm/glm.hpp>

#include "../abstraction/UnifromVariableSubject.h"
#include <GL/glew.h>

class UniformVariableVec3 : public Observer
{
public:
	UniformVariableVec3(UniformVariableSubject<glm::vec3>* subject, GLint uniform_location);
	~UniformVariableVec3();
	void Update() override;
	void Use();
private:
	glm::vec3 value;
	GLint uniform_location = -1;
	UniformVariableSubject<glm::vec3>* subject;
};