#include "SimpleDrawableObject.h"
#include "../EmptyModel.h"

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
	auto emptyModel = dynamic_cast<EmptyModel*>(model);

	if(emptyModel != nullptr)
	{
		return;
	}

	shader->SetTransformation(transformation);
	shader->Use();
	model->DrawModel();
	shader->Unuse();
}

ShaderProgram* SimpleDrawableObject::GetShader() const
{
	return shader;
}

Transformation* SimpleDrawableObject::GetTransformation() const
{
	return transformation;
}

Model* SimpleDrawableObject::GetModel() const
{
	return model;
}

std::vector<std::pair<UniformVariableSubject<glm::vec3>*, std::string>> SimpleDrawableObject::GetLightSubjects()
{
	return std::vector<std::pair<UniformVariableSubject<glm::vec3>*, std::string>>();
}
