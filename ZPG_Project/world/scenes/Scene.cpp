#include "Scene.h"
#include "../projections/PrespectiveProjection.h"
#include "../../defaults.h"

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

	if (lightSource != nullptr)
	{
		shaderProgram->AddUniformVe3Variable(lightSource, DEFAULT_LIGHT_POSITION_NAME);
	}

	shaderProgram->Update();
}

void Scene::UseLight(float x, float y, float z)
{
	if (lightSource == nullptr)
	{
		lightSource = new LightSource();
	}
	
	lightSource->SetPosition(x, y, z);

	for (auto shaderProgram : shaderPrograms)
	{
		shaderProgram->AddUniformVe3Variable(lightSource, DEFAULT_LIGHT_POSITION_NAME);
	}
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
