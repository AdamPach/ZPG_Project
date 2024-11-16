#include "EmptyModel.h"

EmptyModel::EmptyModel()
{
	model_center = glm::vec3(0, 0, 0);
}

void EmptyModel::DrawModel()
{
}

glm::vec3 EmptyModel::GetModelCenter()
{
	return model_center;
}

EmptyModel* EmptyModel::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EmptyModel();
	}

	return instance;
}

EmptyModel* EmptyModel::instance = nullptr;
