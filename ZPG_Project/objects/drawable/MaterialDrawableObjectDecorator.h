#pragma once

#include "../materials/Material.h"
#include "../../shaders/MaterialShaderProgram.h"
#include "DrawableObjectDecorator.h"

class MaterialDrawableObjectDecorator : public DrawableObjectDecorator
{
public:
	MaterialDrawableObjectDecorator(DrawableObject* drawableObject, MaterialGetter* material);
	~MaterialDrawableObjectDecorator();
	void Draw() override;
private:
	MaterialGetter* material;
};