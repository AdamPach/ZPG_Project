#include "MaterialDrawableObject.h"

MaterialDrawableObject::MaterialDrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation, Material* material)
	: DrawableObject(model, shader, transformation)
{
	this->material = material;
}

MaterialDrawableObject::~MaterialDrawableObject()
{
	delete material;
}

void MaterialDrawableObject::DrawObject()
{
	shader->SetMaterialColor(material->GetColor());
	DrawableObject::DrawObject();
}
