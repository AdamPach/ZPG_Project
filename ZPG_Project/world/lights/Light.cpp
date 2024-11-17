#include "Light.h"
#include "../../defaults.h"

Light::Light(glm::vec3 color)
{
	this->position = glm::vec3(0, 0, 0);
	colorSubject.SetValue(color);
	typeSubject.SetValue(1);
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

std::vector<std::pair<Subject*, std::string>> Light::GetSubjects()
{
	std::vector<std::pair<Subject*, std::string>> subjects;

	subjects.push_back(std::pair<TypedDataProviderSubject<glm::vec3>*, std::string>(&positionSubject, DEFAULT_LIGHT_POSITION_NAME));
	subjects.push_back(std::pair<TypedDataProviderSubject<glm::vec3>*, std::string>(&colorSubject, DEFAULT_LIGHT_COLOR_NAME));
	subjects.push_back(std::pair<TypedDataProviderSubject<int>*, std::string>(&typeSubject, DEFAULT_LIGHT_TYPE_NAME));

	return subjects;
}
