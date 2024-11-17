#include "SpotLight.h"
#include "../../defaults.h"

SpotLight::SpotLight(TypedDataProviderSubject<glm::vec3>* frontVectorSubject, glm::vec3 color, float cutOff) : Light(2, color)
{
	this->frontVectorSubject = frontVectorSubject;
	cutOffSubject.SetValue(cutOff);
}

std::vector<std::pair<Subject*, std::string>> SpotLight::GetSubjects()
{
	auto subjects = Light::GetSubjects();

	subjects.push_back(std::make_pair(frontVectorSubject, DEFAULT_SPOT_LIGHT_DIRECTION_NAME));
	subjects.push_back(std::make_pair(&cutOffSubject, DEFAULT_SPOT_LIGHT_CUT_OFF_NAME));

	return subjects;
}