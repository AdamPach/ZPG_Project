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

	shaderProgram->AddUniformMat4Variable(camera->GetViewSubject(), DEFAULT_VIEW_MATRIX_NAME);

	shaderProgram->AddUniformMat4Variable(camera->GetProjectionSubject(), DEFAULT_PROJECTION_MATRIX_NAME);

	shaderProgram->AddUniformIntVariable(&lightsCountSubject, DEFAULT_LIGHTS_COUNT_NAME);
}

ShaderProgram* Scene::GetShaderProgram(const char* programName)
{
	return shaderPrograms[programName];
}

void Scene::UseCameraPosition()
{
	for (auto shaderProgram : shaderPrograms)
	{
		shaderProgram.second->AddUniformVec3Variable(camera->GetPositionSubject(), DEFAULT_CAMERA_POSITION_NAME);
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

void Scene::PrepareLights()
{
	int counter = 0;

	for (auto object : objects)
	{
		for (auto subjectPair : object->GetLightSubjects())
		{
			for (auto shaderProgram : shaderPrograms)
			{
				std::string name = DEFAULT_LIGHTS_NAME;
				name += "[" + std::to_string(counter) + "]." + subjectPair.second;
				shaderProgram.second->AddUniformVec3Variable(subjectPair.first, name.c_str());
			}
			counter++;
		}
	}

	lightsCountSubject.SetValue(counter);
}

void Scene::Draw()
{
	HandleMovement();

	for (auto object : objects)
	{
		object->Draw();
	}
}

Scene* Scene::Init()
{
	InitShaders();
	InitScene();

	PrepareLights();

	return this;
}
