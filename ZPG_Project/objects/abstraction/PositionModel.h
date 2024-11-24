#pragma once

#include "Model.h"

class PositionModel : public Model
{
public:
	PositionModel(float* points, int length);
	~PositionModel();
	void DrawModel() override;
	glm::vec3 GetModelCenter() override;
};