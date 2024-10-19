#include "Rotation.h"

Rotation::Rotation(float angle, glm::vec3 axis)
{
	transformationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
}
