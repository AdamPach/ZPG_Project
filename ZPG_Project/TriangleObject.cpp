#include "TriangleObject.h"

TriangleObject::TriangleObjectBuilder::~TriangleObjectBuilder()
{
	if (data != nullptr && !is_built)
	{
		delete[] data;
	}
}

void TriangleObject::TriangleObjectBuilder::AddObjectData(float* object_data, int length)
{
	this->data = new float[length];

	this->length = length;

	for (int i = 0; i < length; i++)
	{
		this->data[i] = object_data[i];
	}
}

void TriangleObject::TriangleObjectBuilder::AddPoints(int start_in_arr, int count_in_arr)
{
	points_start = start_in_arr;
	points_count = count_in_arr;
	has_points = true;
}

void TriangleObject::TriangleObjectBuilder::AddColors(int start_in_arr, int count_in_arr)
{
	colors_start = start_in_arr;
	colors_count = count_in_arr;
	has_colors = true;
}

TriangleObject* TriangleObject::TriangleObjectBuilder::Build()
{
	is_built = true;

	int point_length = 0;

	if (has_points)
	{
		point_length += points_count;
	}

	if (has_colors)
	{
		point_length += colors_count;
	}

	return new TriangleObject(
		data,
		length / point_length,
		has_points ? points_start : -1,
		points_count,
		has_colors ? colors_start : -1,
		colors_count);
}

TriangleObject::TriangleObject(
	float* object_data,
	int count,
	int point_start,
	int point_count,
	int colors_start,
	int colors_count)
{

	data = object_data;
	//vertex buffer object (VBO)

	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

	//Vertex Array Object (VAO)

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	if (point_start != -1)
	{
		glEnableVertexAttribArray(0);
	}

	if (colors_start != -1)
	{
		glEnableVertexAttribArray(1);
	}

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	if (point_start != -1)
	{
		glVertexAttribPointer(0, point_start, GL_FLOAT, GL_FALSE, sizeof(float) * count, 0);
	}

	if (colors_start != -1)
	{
		glVertexAttribPointer(1, colors_start, GL_FLOAT, GL_FALSE, sizeof(float) * count, (GLvoid*)sizeof(float) * point_start);
	}
}

TriangleObject::~TriangleObject()
{
	if (data != nullptr)
	{
		delete[] data;
	}
}
