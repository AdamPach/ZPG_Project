#include "Scene.h"
#include "PrespectiveProjection.h"
#include "../defaults.h"

Scene::Scene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler)
{
	camera = new Camera(new PrespectiveProjection(45, WINDOW_WIDTH / WINDOW_HEIGHT, 0.1f, 400));

	this->keyboardHandler = keyboardHander;
	this->mouseHandler = mouseHandler;
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

	shaderProgram->Update();
}

void Scene::HandleMovement()
{
	for (auto key : keyboardHandler->GetPressedKeys())
	{
		if (key == W)
		{
			camera->ProcessKeyboardMovement(FORWARD);
		}
		else if (key == A)
		{
			camera->ProcessKeyboardMovement(LEFT);
		}
		else if (key == S)
		{
			camera->ProcessKeyboardMovement(BACKWARD);
		}
		else if (key == D)
		{
			camera->ProcessKeyboardMovement(RIGHT);
		}
	}

	camera->ProcessMouseMovement(mouseHandler->GetXOffset(), mouseHandler->GetYOffset());
}

void Scene::Draw()
{
	HandleMovement();

	for (auto object : objects)
	{
		object->DrawObject();
	}
}
