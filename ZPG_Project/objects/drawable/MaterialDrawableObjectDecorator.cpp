#include "MaterialDrawableObjectDecorator.h"

MaterialDrawableObjectDecorator::MaterialDrawableObjectDecorator(DrawableObject* drawableObject, MaterialGetter* material) : DrawableObjectDecorator(drawableObject)
{
	this->material = material;
}

MaterialDrawableObjectDecorator::~MaterialDrawableObjectDecorator()
{

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

	if (materialShader != nullptr)
	{
		materialShader->UnsetMaterial();
	}
}
