#pragma once

#include <GL/glew.h>

class Shader
{
public:
	void virtual AttachShader(GLuint shader_program);
protected:
	GLuint shader;
};

