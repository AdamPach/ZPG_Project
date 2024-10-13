#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shader, Transformation* transformation)
{
	this->model = model;
	this->shader = shader;
	this->transformation = transformation;
}

void DrawableObject::DrawObject()
{
	shader->Use();
	transformation->Use();
	model->DrawModel();
}


