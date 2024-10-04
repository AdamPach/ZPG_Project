#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ShaderProgram.h"

class Object
{
public:
	virtual void DrawObject() = 0;
	virtual void AddShaderProgram(ShaderProgram* shader);
protected:
	ShaderProgram* shader = nullptr;
};

