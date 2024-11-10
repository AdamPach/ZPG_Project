#include "SimpleDrawableObject.h"

SimpleDrawableObject::SimpleDrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation)
{
	this->model = model;
	this->shader = shader;
	this->transformation = transformation;
}

SimpleDrawableObject::~SimpleDrawableObject()
{
	delete transformation;
}

void SimpleDrawableObject::Draw()
{
	shader->Use(transformation);
	model->DrawModel();
}

ShaderProgram* SimpleDrawableObject::GetShader() const
{
	return shader;
}
