#include "Scene.h"
#include "../../defaults.h"

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

TypedDataProviderSubject<glm::vec3>* Scene::GetCameraPositionSubject()
{
	return camera->GetPositionSubject();
}

TypedDataProviderSubject<glm::vec3>* Scene::GetCameraFrontSubject()
{
	return camera->GetFrontSubject();
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
	for (auto key : keyboardHandler.GetPressedKeys())
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

	camera->ProcessMouseMovement(mouseHandler.GetXOffset(), mouseHandler.GetYOffset());
}

void Scene::PrepareLights()
{
	int counter = 0;

	for (auto object : objects)
	{
		bool isLight = false;
		for (auto subjectPair : object->GetLightSubjects())
		{
			for (auto shaderProgram : shaderPrograms)
			{
				std::string name = DEFAULT_LIGHTS_NAME;
				name += "[" + std::to_string(counter) + "]." + subjectPair.second;

				auto vec3Subject = dynamic_cast<TypedDataProviderSubject<glm::vec3>*>(subjectPair.first);

				if (vec3Subject != nullptr)
				{
					shaderProgram.second->AddUniformVec3Variable(vec3Subject, name.c_str());
					continue;
				}

				auto intSubject = dynamic_cast<TypedDataProviderSubject<int>*>(subjectPair.first);

				if (intSubject != nullptr)
				{
					shaderProgram.second->AddUniformIntVariable(intSubject, name.c_str());
					continue;
				}

				auto floatSubject = dynamic_cast<TypedDataProviderSubject<float>*>(subjectPair.first);

				if (floatSubject != nullptr)
				{
					shaderProgram.second->AddUniformFloatVariable(floatSubject, name.c_str());
					continue;
				}
			}
			isLight = true;
		}
		counter += isLight ? 1 : 0;
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

InputMediator* Scene::GetInputMediator(Application* application)
{
	if (inputMediator == nullptr)
	{
		inputMediator = new InputMediator(application, &keyboardHandler, &mouseHandler);
	}

	return inputMediator;
}