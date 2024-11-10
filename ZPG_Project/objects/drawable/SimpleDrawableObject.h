#pragma once

#include "../Model.h"
#include "../../shaders/ShaderProgram.h"
#include "../../transformations/Transformation.h"
#include "DrawableObject.h"

class SimpleDrawableObject : public DrawableObject
{
public:
	SimpleDrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation);
	~SimpleDrawableObject();
	void Draw() override;
	ShaderProgram* GetShader() const override;
	Transformation* GetTransformation() const override;
	Model* GetModel() const override;
private:
	Model* model;
	Transformation* transformation; 
	ShaderProgram* shader;
};