#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shader)
{
	this->model = model;
	this->shader = shader;
}

void DrawableObject::DrawObject()
{
	shader->Use();
	model->DrawModel();
}


