#pragma once

#include "Model.h"
#include "ShaderProgram.h"

class DrawableObject
{
public:
	DrawableObject(Model* model, ShaderProgram* shader);
	void DrawObject();
private:
	Model* model;
	ShaderProgram* shader;
};