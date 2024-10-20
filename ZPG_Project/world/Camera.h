#pragma once

#include <glm/glm.hpp>

#include "../abstraction/Observer.h"

class Camera : public Subject
{
public:
	glm::mat4 GetViewMatrix();
};

