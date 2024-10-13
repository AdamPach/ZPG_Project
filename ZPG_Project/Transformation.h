#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transformation
{
public:
	Transformation(GLint unimform_id);
	void Use();
private:
	GLint unimform_id;
};

