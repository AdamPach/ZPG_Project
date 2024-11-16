#include "MaterialDrawableObjectDecorator.h"

MaterialDrawableObjectDecorator::MaterialDrawableObjectDecorator(DrawableObject* drawableObject, Material* material) : DrawableObjectDecorator(drawableObject)
{
	this->material = material;
}

MaterialDrawableObjectDecorator::~MaterialDrawableObjectDecorator()
{
	delete material;
}

void MaterialDrawableObjectDecorator::Draw()
{
	GetShader()->SetMaterial(material);
	DrawableObjectDecorator::Draw();
}
