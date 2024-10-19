#include "Translation.h"

Translation::Translation(glm::vec3 direction)
{
	transformationMatrix = glm::translate(glm::mat4(1.0f), direction);
}
