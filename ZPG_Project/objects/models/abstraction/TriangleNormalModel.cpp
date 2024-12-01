#include "TriangleNormalModel.h"

TriangleNormalModel::TriangleNormalModel(float* points, int length)
{
	this->length = length;
	this->points = new float[this->length];

	std::memcpy(this->points, points, this->length);

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
	delete[] points;

	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void TriangleNormalModel::DrawModel()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, length / 6);
}

glm::vec3 TriangleNormalModel::GetModelCenter()
{
	if (model_center != glm::vec3(-1, -1, -1))
	{
		return model_center;
	}

	model_center = glm::vec3(0.0f, 0.0f, 0.0f);

	for (int i = 0; i < length; i += 6)
	{
		model_center.x += points[i];
		model_center.y += points[i + 1];
		model_center.z += points[i + 2];
	}

	model_center.x /= length / 6;
	model_center.y /= length / 6;
	model_center.z /= length / 6;

	return model_center;
}
