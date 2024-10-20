#include "PrespectiveProjection.h"
#include <glm/ext/matrix_clip_space.hpp>

PrespectiveProjection::PrespectiveProjection(float fov, float aspect, float near, float far)
{
	projectionMatrix = glm::perspective(glm::radians(fov), aspect, near, far);
}

glm::mat4 PrespectiveProjection::GetProjectionMatrix()
{
	return projectionMatrix;
}

