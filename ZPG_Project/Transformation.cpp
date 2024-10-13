#include "Transformation.h"
#include <GLFW/glfw3.h>

Transformation::Transformation(GLint unimform_id)
{
	this->unimform_id = unimform_id;
}

void Transformation::Use()
{
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::rotate(M, glm::radians((float)glfwGetTime() * 50.f), glm::vec3(0.0f, 1.0f, 0.0f));

	glUniformMatrix4fv(unimform_id, 1, GL_FALSE, &M[0][0]);
}
