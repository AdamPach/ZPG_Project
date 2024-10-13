#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation)
{
	this->model = model;
	this->shader = shader;
	this->transformation = transformation;
}

DrawableObject::~DrawableObject()
{
	delete model;
	delete shader;
	delete transformation;
}

void DrawableObject::DrawObject()
{
	shader->Use();
	transformation->Use();
	model->DrawModel();
}


