#pragma once

#include "Light.h"

class SpotLight : public Light
{
public:
	SpotLight(glm::vec3 color);
	std::vector<std::pair<Subject*, std::string>> GetSubjects()override;
};