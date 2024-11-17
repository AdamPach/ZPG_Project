#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "LightPositionSubject.h"
#include "LightColorSubject.h"
#include "LightTypeSubject.h"
#include <vector>
#include <string>

class Light
{
public:
	Light(glm::vec3 color);
	void SetPosition(glm::vec3 position);
	std::vector<std::pair<Subject*, std::string>> GetSubjects();
private:
	LightPositionSubject positionSubject;
	LightColorSubject colorSubject;
	LightTypeSubject typeSubject;

	glm::vec3 position;
};