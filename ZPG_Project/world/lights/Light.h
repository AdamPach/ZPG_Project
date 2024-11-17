#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "LightPositionSubject.h"
#include <vector>
#include <string>

class Light
{
public:
	Light(glm::vec3 color);
	void SetPosition(glm::vec3 position);
	std::vector<std::pair<TypedDataProviderSubject<glm::vec3>*, std::string>> GetSubjects();
private:
	LightPositionSubject positionSubject;
	glm::vec3 position;
};