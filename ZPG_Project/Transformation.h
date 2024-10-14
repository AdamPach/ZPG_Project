#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "TransformationPartContainer.h"
#include "TransformationPart.h"

class Transformation
{
public:
	Transformation();
	Transformation(TransformationPartContainer* container);
	~Transformation();
	void AddPart(TransformationPart* part);
	glm::mat4 GetTransformation();
private:
	glm::mat4* M;
	TransformationPartContainer* transformationPartContainer;
};

