#pragma once

#include "Light.h"
#include "../../abstraction/UnifromVariableSubject.h"

class SpotLight : public Light
{
public:
	SpotLight(TypedDataProviderSubject<glm::vec3>* frontVectorSubject, glm::vec3 color);
	std::vector<std::pair<Subject*, std::string>> GetSubjects()override;
private:
	TypedDataProviderSubject<glm::vec3>* frontVectorSubject;
};