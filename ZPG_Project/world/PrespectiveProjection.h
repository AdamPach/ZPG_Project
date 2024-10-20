#pragma once

#include "Projection.h"

class PrespectiveProjection : public Projection
{
public:
	PrespectiveProjection(float fov, float aspect, float near, float far);
	glm::mat4 GetProjectionMatrix() override;
private:
	glm::mat4 projectionMatrix;
};