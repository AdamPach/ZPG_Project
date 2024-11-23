#pragma once

#include <vector>
#include <map>

#include "../../objects/drawable/SimpleDrawableObject.h"
#include "../../shaders/ShaderProgram.h"
#include "../cameras/Camera.h"
#include "../../input/KeyboardHandler.h"
#include "../../input/MouseHandler.h"
#include "../lights/LightsCountSubject.h"
#include "../../shaders/ShaderProgramBuilder.h"
#include "../../input/InputMediator.h"

class Scene
{
public:
	Scene(MouseHandler* mouseHandler);
	~Scene();

	void Draw();
	Scene* Init();
	InputMediator* GetInputMediator(RequestHandler<ChangeSceneRequest>* change_scene_handler, RequestHandler<ExitRequest>* exit_handler);

protected:
	void AddObject(DrawableObject* object);
	void AddShaderProgram(ShaderProgram* shaderProgram, const char * programName);
	ShaderProgram* GetShaderProgram(const char* programName);
	TypedDataProviderSubject<glm::vec3>* GetCameraPositionSubject();
	TypedDataProviderSubject<glm::vec3>* GetCameraFrontSubject();

	void UseCameraPosition();

	virtual void InitShaders() = 0;
	virtual void InitScene() = 0;

private:
	std::vector<DrawableObject*> objects;
	std::map<std::string, ShaderProgram*> shaderPrograms;

	Camera* camera = nullptr;

	InputMediator* inputMediator = nullptr;

	KeyboardHandler keyboardHandler;
	MouseHandler* mouseHandler;
	LightsCountSubject lightsCountSubject;

	void HandleMovement();
	void PrepareLights();
};