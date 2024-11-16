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
	ShaderProgram* shader = GetShader();

	MaterialShaderProgram* materialShader = dynamic_cast<MaterialShaderProgram*>(shader);

	if (materialShader != nullptr)
	{
		materialShader->SetMaterial(material);
	}

	DrawableObjectDecorator::Draw();
}
