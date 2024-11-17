#include "Light.h"
#include "../../defaults.h"

Light::Light(glm::vec3 color)
{
	this->position = glm::vec3(0, 0, 0);
}

void Light::SetPosition(glm::vec3 position)
{
	if (this->position == position)
	{
		return;
	}

	this->position = position;
	positionSubject.SetValue(position);
}

std::vector<std::pair<TypedDataProviderSubject<glm::vec3>*, std::string>> Light::GetSubjects()
{
	std::vector<std::pair<TypedDataProviderSubject<glm::vec3>*, std::string>> subjects;

	subjects.push_back(std::pair<TypedDataProviderSubject<glm::vec3>*, std::string>(&positionSubject, DEFAULT_LIGHT_POSITION_NAME));

	return subjects;
}
