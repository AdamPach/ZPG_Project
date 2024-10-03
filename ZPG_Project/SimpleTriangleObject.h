#pragma once

#include "Object.h"

class SimpleTriangleObject : public Object
{
public:
	SimpleTriangleObject();
	void DrawObject();
private:
	GLuint VBO, VAO;
};

