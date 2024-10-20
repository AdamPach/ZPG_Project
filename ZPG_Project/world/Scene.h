#pragma once

#include <vector>

#include "../objects/DrawableObject.h"
#include "../shaders/ShaderProgram.h"
#include "../world/Camera.h"
#include "../handlers/KeyboardHandler.h"
#include "../handlers/MouseHandler.h"

class Scene
{
public:
	Scene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
	~Scene();

	void AddObject(DrawableObject* object);
	void AddShaderProgram(ShaderProgram* shaderProgram);
	void Draw();

private:
	std::vector<DrawableObject*> objects;
	std::vector<ShaderProgram*> shaderPrograms;
	Camera* camera;
	KeyboardHandler* keyboardHandler;
	MouseHandler* mouseHandler;

	void HandleMovement();
};