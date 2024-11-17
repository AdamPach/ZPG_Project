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
	void SetPosition(glm::vec3 position);
	virtual std::vector<std::pair<Subject*, std::string>> GetSubjects();
protected:
	Light(int lightType, glm::vec3 color);
private:
	LightPositionSubject positionSubject;
	LightColorSubject colorSubject;
	LightTypeSubject typeSubject;
	glm::vec3 position;
};