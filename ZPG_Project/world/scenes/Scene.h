#pragma once

#include <vector>
#include <map>

#include "../../objects/drawable/SimpleDrawableObject.h"
#include "../../shaders/ShaderProgram.h"
#include "../cameras/Camera.h"
#include "../../handlers/KeyboardHandler.h"
#include "../../handlers/MouseHandler.h"
#include "../lights/Light.h"

enum LightSettings{ Position, Color, Both };

class Scene
{
public:
	Scene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
	~Scene();

	void Draw();
	Scene* Init();

protected:
	void AddObject(DrawableObject* object);
	void AddShaderProgram(ShaderProgram* shaderProgram, const char * programName);
	ShaderProgram* GetShaderProgram(const char* programName);

	void UseLight(LightSettings lightSettings);
	void SetLigthPosition(float x, float y, float z);
	void SetLightColor(float r, float g, float b);

	void UseCameraPosition();

	virtual void InitShaders() = 0;
	virtual void InitScene() = 0;

private:
	std::vector<DrawableObject*> objects;
	std::map<std::string, ShaderProgram*> shaderPrograms;

	Camera* camera = nullptr;
	Light* light = nullptr;

	KeyboardHandler* keyboardHandler;
	MouseHandler* mouseHandler;

	void HandleMovement();
};