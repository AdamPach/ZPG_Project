#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Model
{
public:
	virtual void DrawModel() = 0;
	virtual glm::vec3 GetModelCenter() = 0;
protected:
	float* points;
	int length;
	GLuint VBO, VAO;
	glm::vec3 model_center = glm::vec3(-1, -1, -1);
};
