#include "OrthoProjection.h"
#include <glm/ext/matrix_clip_space.hpp>

OrthoProjection::OrthoProjection(float left, float right, float bottom, float top, float near, float far)
{
	projectionMatrix = glm::ortho(left, right, bottom, top, near, far);
}

glm::mat4 OrthoProjection::GetProjectionMatrix()
{
	return glm::mat4();
}
