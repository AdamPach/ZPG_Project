#pragma once

#include "../materials/Material.h"
#include "../../shaders/MaterialShaderProgram.h"
#include "DrawableObjectDecorator.h"

class MaterialDrawableObjectDecorator : public DrawableObjectDecorator
{
public:
	MaterialDrawableObjectDecorator(DrawableObject* drawableObject, Material* material);
	~MaterialDrawableObjectDecorator();
	void Draw() override;
private:
	Material* material;
};