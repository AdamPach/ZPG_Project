#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation)
{
	this->model = model;
	this->shader = shader;
	this->transformation = transformation;
}

DrawableObject::~DrawableObject()
{
	delete transformation;
}

void DrawableObject::DrawObject()
{
	shader->Use(transformation);
	model->DrawModel();
}


