#include "BezierMovement.h"

BezierMovement::BezierMovement(glm::vec3 start, glm::vec3 control1, glm::vec3 control2, glm::vec3 end, float duration)
{
	pointMatrix = glm::mat4x3(start, control1, control2, end);

	bezierMatrix = glm::mat4(
		-1, 3, -3, 1,
		3, -6, 3, 0,
		-3, 3, 0, 0,
		1, 0, 0, 0);

	this->duration = duration;
}

bool BezierMovement::IsDynamic()
{
	return true;
}

glm::mat4 BezierMovement::GetMatrix()
{
	if(t < 1)
	{
		t += 0.003f;
	}

	glm::vec4 tVec = glm::vec4(t * t * t, t * t, t, 1);
	glm::vec3 result = tVec * bezierMatrix * glm::transpose(pointMatrix);
	return glm::translate(glm::mat4(1), result);
}
