#pragma once

#include <vector>

#include "Shader.h"
#include "Transformation.h"

class ShaderProgram
{
public:
	ShaderProgram(int count_of_shaders = 2);
	~ShaderProgram();

	void AddShader(Shader* shader);
	void Compile();
	void Use();
	void Check();

	GLint GetUniformLocation(const char* name);
private:
	std::vector<Shader*> shaders;
	GLuint shader_program;
};

