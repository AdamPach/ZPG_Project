#pragma once

#include "Light.h"

class PointLight : public Light
{
public:
	PointLight(glm::vec3 color);
	std::vector<std::pair<Subject*, std::string>> GetSubjects()override;
};