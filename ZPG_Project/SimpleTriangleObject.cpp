#include "SimpleTriangleObject.h"

float points[] = {
   -0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
   -0.5f, -0.5f, 0.0f
};

SimpleTriangleObject::SimpleTriangleObject()
{
	//vertex buffer object (VBO)

	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	//Vertex Array Object (VAO)

	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void SimpleTriangleObject::DrawObject()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
