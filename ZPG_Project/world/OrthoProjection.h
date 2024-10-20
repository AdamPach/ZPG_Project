#pragma once

#include "Projection.h"

class OrthoProjection : public Projection
{
public:
	OrthoProjection(float left, float right, float bottom, float top, float near, float far);
	glm::mat4 GetProjectionMatrix() override;
private:
	glm::mat4 projectionMatrix;
};