#pragma once

#include "TransformationBasic.h"

class RandomDynamcMovement : public TransformationBasic
{
public:
	RandomDynamcMovement();
	glm::mat4 GetMatrix() override;
	bool IsDynamic() override;
private:
	double CountNewCoordinates();
};