#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "TransformationComposite.h"
#include "TransformationBasic.h"

class Transformation
{
public:
	Transformation(TransformationComposite* container);
	~Transformation();
	void AddPart(TransformationBasic* part);
	glm::mat4 GetTransformationMatrix();
private:
	TransformationComposite* transformationPartContainer;
};

