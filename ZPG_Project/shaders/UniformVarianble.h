#pragma once

#include <glm/glm.hpp>

#include "../abstraction/UnifromVariableSubject.h"
#include <GL/glew.h>

class UniformVariable : public Observer
{
public:
	virtual void Use() = 0;
protected:
	GLint uniform_location = -1;
};