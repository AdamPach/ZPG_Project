#pragma once

#include "Model.h"
#include "../shaders/ShaderProgram.h"
#include "../transformations/Transformation.h"

class DrawableObject
{
public:
	DrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation);
	~DrawableObject();
	virtual void DrawObject();
protected:
	ShaderProgram* shader;	
private:
	Model* model;
	Transformation* transformation;
};