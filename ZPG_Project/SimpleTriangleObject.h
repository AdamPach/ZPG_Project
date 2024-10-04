#pragma once

#include "Object.h"

class SimpleTriangleObject : public Object
{
public:
	SimpleTriangleObject(float points[], int length, int attribute_length);
	void DrawObject();
private:
	float* triangle_points;
	int points_to_draw;
	GLuint VBO, VAO;
};

