#include "SimpleTriangleObject.h"

SimpleTriangleObject::SimpleTriangleObject(float points[], int length, int attribute_length)
{
	triangle_points = points;
	this->points_to_draw = length / attribute_length;

	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, length, triangle_points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, attribute_length, GL_FLOAT, GL_FALSE, 0, NULL);
}

void SimpleTriangleObject::DrawObject()
{
	shader->Use();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, points_to_draw);
}
