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
		delete shaderProgram.second;
	}

	delete camera;
}

void Scene::AddObject(DrawableObject* object)
{
	objects.push_back(object);
}

void Scene::AddShaderProgram(ShaderProgram* shaderProgram, const char* programName)
{
	shaderPrograms[programName] = shaderProgram;

	shaderProgram->SetCamera(this->camera);

	shaderProgram->Update();
}

ShaderProgram* Scene::GetShaderProgram(const char* programName)
{
	return shaderPrograms[programName];
}

void Scene::UseLight(LightSettings lightSettings)
{
	if (light == nullptr)
	{
		light = new Light();
	}
	
	for (auto shaderProgram : shaderPrograms)
	{
		switch (lightSettings)
		{
		case Position:
			shaderProgram.second->AddUniformVe3Variable(light->GetPositionSubject(), DEFAULT_LIGHT_POSITION_NAME);
			break;
		case Color:
			shaderProgram.second->AddUniformVe3Variable(light->GetColorSubject(), DEFAULT_LIGHT_COLOR_NAME);
			break;
		case Both:
			shaderProgram.second->AddUniformVe3Variable(light->GetPositionSubject(), DEFAULT_LIGHT_POSITION_NAME);
			shaderProgram.second->AddUniformVe3Variable(light->GetColorSubject(), DEFAULT_LIGHT_COLOR_NAME);
			break;
		default:
			break;
		}
	}
}

void Scene::SetLigthPosition(float x, float y, float z)
{
	light->SetPosition(x, y, z);
}

void Scene::SetLightColor(float r, float g, float b)
{
	light->SetColor(r, g, b);
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

Scene* Scene::Init()
{
	InitShaders();
	InitScene();

	return this;
}
