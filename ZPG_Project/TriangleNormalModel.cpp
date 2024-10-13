#include "TriangleNormalModel.h"

TriangleNormalModel::TriangleNormalModel(float* points, int length)
{
	this->length = length;

	glGenBuffers(1, &VBO); 
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, length, points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO); 
	glBindVertexArray(VAO); 
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(sizeof(float) * 3));
}

TriangleNormalModel::~TriangleNormalModel()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void TriangleNormalModel::DrawModel()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, length / 6);
}
