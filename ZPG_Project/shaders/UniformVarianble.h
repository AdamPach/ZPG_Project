#pragma once

#include <glm/glm.hpp>

#include "../abstraction/UnifromVariableSubject.h"
#include <GL/glew.h>

class UniformVariable : public Observer
{
protected:
	UniformVariable(GLuint shader_program, GLint uniform_location);
	GLint uniform_location = -1;
	GLuint shader_program = -1;
};