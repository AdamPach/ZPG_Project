#pragma once

#include "Object.h"

class TriangleObject : public Object
{
public:
	~TriangleObject();
	void DrawObject();
private:
	TriangleObject(
		float *object_data,
		int count,
		int point_start,
		int point_count,
		int colors_start,
		int colors_count);

	float* data = nullptr;
	GLuint VBO, VAO;
public:
	class TriangleObjectBuilder
	{
	public:
		~TriangleObjectBuilder();
		void AddObjectData(float * object_data, int length);
		void AddPoints(int start_in_arr, int count_in_arr);
		void AddColors(int start_in_arr, int count_in_arr);

		TriangleObject* Build();
	private:
		float * data = nullptr;
		bool is_built = false;
		bool has_points = false, has_colors = false;
		int points_start, points_count, colors_start, colors_count;
		int length = 0;
	};
};

