#pragma once

#include "../../shaders/ShaderProgram.h"
#include "../../transformations/Transformation.h"
#include "../Model.h"
#include <vector>

class DrawableObject
{
public:
	virtual void Draw() = 0;
	virtual ShaderProgram* GetShader() const = 0;
	virtual Transformation* GetTransformation() const = 0;
	virtual Model* GetModel() const = 0;
	virtual std::vector<std::pair<Subject*, std::string>> GetLightSubjects() = 0;
};