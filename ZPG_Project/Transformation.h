#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include <vector>

#include "TransformationPart.h"

class Transformation
{
public:
	Transformation(GLint unimform_id);
	Transformation(GLint unimform_id, std::vector<TransformationPart*> parts);
	~Transformation();
	void AddPart(TransformationPart* part);
	void Use();
private:
	GLint unimform_id;
	std::vector<TransformationPart*> parts;
};

