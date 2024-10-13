#pragma once

#include "Model.h"
#include "ShaderProgram.h"
#include "Transformation.h"

class DrawableObject
{
public:
	DrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation);
	~DrawableObject();
	void DrawObject();
private:
	Model* model;
	ShaderProgram* shader;
	Transformation* transformation;
};