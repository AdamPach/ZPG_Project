#include "PointLight.h"

PointLight::PointLight(glm::vec3 color) : Light(1, color)
{
}

std::vector<std::pair<Subject*, std::string>> PointLight::GetSubjects()
{
	return Light::GetSubjects();
}
