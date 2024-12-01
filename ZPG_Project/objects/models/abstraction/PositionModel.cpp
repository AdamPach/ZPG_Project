#include "PositionModel.h"

PositionModel::PositionModel(float* points, int length)
{
	this->length = length;
	this->points = points;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, length, points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

PositionModel::~PositionModel()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void PositionModel::DrawModel()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, length / 3);
	glBindVertexArray(0);
}

glm::vec3 PositionModel::GetModelCenter()
{
	if (model_center != glm::vec3(-1, -1, -1))
	{
		return model_center;
	}

	model_center = glm::vec3(0.0f, 0.0f, 0.0f);

	for (int i = 0; i < length; i += 3)
	{
		model_center.x += points[i];
		model_center.y += points[i + 1];
		model_center.z += points[i + 2];
	}

	model_center.x /= length / 3;
	model_center.y /= length / 3;
	model_center.z /= length / 3;

	return model_center;
}
