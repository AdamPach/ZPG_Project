#include "SpotLight.h"
#include "../../defaults.h"

SpotLight::SpotLight(TypedDataProviderSubject<glm::vec3>* frontVectorSubject, glm::vec3 color) : Light(2, color)
{
	this->frontVectorSubject = frontVectorSubject;
}

std::vector<std::pair<Subject*, std::string>> SpotLight::GetSubjects()
{
	auto subjects = Light::GetSubjects();

	subjects.push_back(std::make_pair(frontVectorSubject, DEFAULT_LIGHT_DIRECTION_NAME));

	return subjects;
}