#pragma once

#include <vector>

#include "../objects/DrawableObject.h"
#include "../shaders/ShaderProgram.h"
#include "../world/Camera.h"

class Scene
{
public:
	Scene();
	~Scene();

	void AddObject(DrawableObject* object);
	void AddShaderProgram(ShaderProgram* shaderProgram);
	void HandleMovement(CameraMovement movement);
	void Draw();

private:

	std::vector<DrawableObject*> objects;
	std::vector<ShaderProgram*> shaderPrograms;
	Camera* camera;
};