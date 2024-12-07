#pragma once

#include "TransformationBasic.h"

class BezierMovement : public TransformationBasic
{
public:
	BezierMovement(glm::vec3 start, glm::vec3 control1, glm::vec3 control2, glm::vec3 end, float duration);
	bool IsDynamic() override;
	glm::mat4 GetMatrix() override;
private:
	glm::mat4x3 pointMatrix;
	glm::mat4 bezierMatrix;
	float duration;
	float t = 0;
	bool tRising = true;
};