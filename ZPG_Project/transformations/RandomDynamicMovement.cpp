#include "RandomDynamicMovement.h"

RandomDynamcMovement::RandomDynamcMovement()
{
	transformationMatrix = glm::mat4(1.0f);
}

glm::mat4 RandomDynamcMovement::GetMatrix()
{
	glm::vec3 translation = glm::vec3(CountNewCoordinates(), CountNewCoordinates(), CountNewCoordinates());

	transformationMatrix = glm::translate(transformationMatrix, translation);

	return transformationMatrix;
}

bool RandomDynamcMovement::IsDynamic()
{
	return true;
}

double RandomDynamcMovement::CountNewCoordinates()
{
	return (rand() % 601 - static_cast<double>(300)) / 1000;
}
