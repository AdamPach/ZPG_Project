#pragma once

#include "materials/Material.h"
#include "DrawableObject.h"

class MaterialDrawableObject : public DrawableObject
{
public:
	MaterialDrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation, Material* material);
	~MaterialDrawableObject();
	void DrawObject() override;
private:
	Material* material;
};