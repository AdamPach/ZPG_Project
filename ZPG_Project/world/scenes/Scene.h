#pragma once

#include <vector>

#include "../../objects/DrawableObject.h"
#include "../../shaders/ShaderProgram.h"
#include "../cameras/Camera.h"
#include "../../handlers/KeyboardHandler.h"
#include "../../handlers/MouseHandler.h"
#include "../lights/LightSource.h"

class Scene
{
public:
	Scene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
	~Scene();

	void Draw();
	virtual Scene* InitScene() = 0;

protected:
	void AddObject(DrawableObject* object);
	void AddShaderProgram(ShaderProgram* shaderProgram);

	void UseLight(float x, float y, float z);

private:
	std::vector<DrawableObject*> objects;
	std::vector<ShaderProgram*> shaderPrograms;

	Camera* camera = nullptr;
	LightSource* lightSource = nullptr;

	KeyboardHandler* keyboardHandler;
	MouseHandler* mouseHandler;

	void HandleMovement();
};