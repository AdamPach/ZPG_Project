#pragma once

#include "Light.h"
#include "../../abstraction/UnifromVariableSubject.h"
#include "SpotLightCutOffSubject.h"

class SpotLight : public Light
{
public:
	SpotLight(TypedDataProviderSubject<glm::vec3>* frontVectorSubject, glm::vec3 color, float cutOff = 15.0f);
	std::vector<std::pair<Subject*, std::string>> GetSubjects()override;
private:
	TypedDataProviderSubject<glm::vec3>* frontVectorSubject;
	SpotLightCutOffSubject cutOffSubject;
};