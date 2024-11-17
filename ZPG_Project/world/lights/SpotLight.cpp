#include "SpotLight.h"

SpotLight::SpotLight(glm::vec3 color) : Light(2, color)
{
}

std::vector<std::pair<Subject*, std::string>> SpotLight::GetSubjects()
{
	return std::vector<std::pair<Subject*, std::string>>();
}
