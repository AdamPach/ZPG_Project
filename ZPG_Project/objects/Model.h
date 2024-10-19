#pragma once

#include <GL/glew.h>

class Model
{
public:
	virtual void DrawModel() = 0;
protected:
	float* model_points;
	int length;
	GLuint VBO, VAO;
};
