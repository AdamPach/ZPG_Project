#pragma once

#include "../../shaders/ShaderProgram.h"

class DrawableObject
{
public:
	virtual void Draw() = 0;
	virtual ShaderProgram* GetShader() const = 0;
};