#pragma once

#include <vector>

#include "Shader.h"
#include "Transformation.h"

class ShaderProgram
{
public:
	~ShaderProgram();

	void AddShader(Shader* shader);
	void Compile();
	void Use();
	void Use(Transformation* transformation, const char * variable_name);
	void Check();

	GLint GetUniformLocation(const char* name);

	class ShaderProgramBuilder
	{
	public:
		ShaderProgramBuilder* AddVertexShader(const char* shader);
		ShaderProgramBuilder* AddFragmentShader(const char* shader);

		ShaderProgram* Build();
	private:
		std::vector<Shader*> shaders;
	};

	static ShaderProgramBuilder* CreateBuilder();
private:
	ShaderProgram(int count_of_shaders = 2);

	std::vector<Shader*> shaders;
	GLuint shader_program;
};

