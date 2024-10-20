#include "Scene.h"

Scene::Scene()
{
	camera = new Camera();
}

Scene::~Scene()
{
	for (auto object : objects)
	{
		delete object;
	}

	for (auto shaderProgram : shaderPrograms)
	{
		delete shaderProgram;
	}

	delete camera;
}

void Scene::AddObject(DrawableObject* object)
{
	objects.push_back(object);
}

void Scene::AddShaderProgram(ShaderProgram* shaderProgram)
{
	shaderPrograms.push_back(shaderProgram);
	shaderProgram->SetCamera(this->camera);
}

void Scene::HandleMovement(CameraMovement movement)
{
	camera->ProcessKeyboardMovement(movement);
}

void Scene::Draw()
{
	for (auto object : objects)
	{
		object->DrawObject();
	}
}
