#pragma once

#include <vector>

#include "Shader.h"

class ShaderProgram
{
public:
	ShaderProgram(int count_of_shaders = 2);
	~ShaderProgram();

	void AddShader(Shader* shader);
	void Compile();
	void Use();
	void Check();
private:
	std::vector<Shader*> shaders;
	GLuint shader_program;	
};

