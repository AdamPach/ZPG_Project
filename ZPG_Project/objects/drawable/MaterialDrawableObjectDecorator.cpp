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
	GetShader()->SetMaterialColor(material->GetColor());
	DrawableObjectDecorator::Draw();
}
