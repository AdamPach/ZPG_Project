#pragma once

#include "Light.h"
#include "../../abstraction/UnifromVariableSubject.h"
#include "SpotLightCutOffSubject.h"
#include "SpotLightOuterCutOffSubject.h"

class SpotLight : public Light
{
public:
	SpotLight(TypedDataProviderSubject<glm::vec3>* frontVectorSubject, glm::vec3 color, float cutOff = 12.5f, float outerCutOff = 20.0f);
	std::vector<std::pair<Subject*, std::string>> GetSubjects()override;
private:
	TypedDataProviderSubject<glm::vec3>* frontVectorSubject;
	SpotLightCutOffSubject cutOffSubject;
	SpotLightOuterCutOffSubject outerCutOffSubject;
};