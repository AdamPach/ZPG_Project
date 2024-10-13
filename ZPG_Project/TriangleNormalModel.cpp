#include "TriangleNormalModel.h"

TriangleNormalModel::TriangleNormalModel(float* points, int length)
{
	model_points = points;
	model_points_length = length;

	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, length, model_points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO); 
	glBindVertexArray(VAO); 
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(sizeof(float) * 3));
}

void TriangleNormalModel::DrawModel()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, model_points_length / 6);
}
