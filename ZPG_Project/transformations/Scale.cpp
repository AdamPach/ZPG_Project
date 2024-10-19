#include "Scale.h"

Scale::Scale(glm::vec3 scale)
{
	transformationMatrix = glm::scale(glm::mat4(1.0f), scale);
}
