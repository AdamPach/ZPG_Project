#pragma once

#include "Model.h"

class TriangleNormalTexturedModel : public Model
{
public:
	TriangleNormalTexturedModel(float* points, int length);
	~TriangleNormalTexturedModel();
	void DrawModel() override;
	glm::vec3 GetModelCenter() override;
};