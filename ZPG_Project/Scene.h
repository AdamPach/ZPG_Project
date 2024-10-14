#pragma once

#include <vector>

#include "DrawableObject.h"
#include "ShaderProgram.h"

class Scene
{
public:
	~Scene();

	void AddObject(DrawableObject* object);
	void AddShaderProgram(ShaderProgram* shaderProgram);
	void Draw();

private:

	std::vector<DrawableObject*> objects;
	std::vector<ShaderProgram*> shaderPrograms;
};