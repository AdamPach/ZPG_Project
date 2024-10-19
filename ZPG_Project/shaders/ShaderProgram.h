#pragma once

#include <vector>
#include <string>


#include "Shader.h"
#include "../transformations/Transformation.h"

class ShaderProgram
{
public:
	~ShaderProgram();

	void Use();
	void Use(Transformation* transformation);

	class ShaderProgramBuilder
	{
	public:
		ShaderProgramBuilder* AddVertexShader(const char* shader);
		ShaderProgramBuilder* AddFragmentShader(const char* shader);
		ShaderProgramBuilder* AddUniform(const char* uniform);

		ShaderProgram* Build();
	private:
		std::vector<Shader*> shaders;
		std::string uniform = "";
	};

	static ShaderProgramBuilder* CreateBuilder();
private:
	ShaderProgram(int count_of_shaders = 2);

	void AddShader(Shader* shader);
	void AddUniform(std::string uniform);
	void Compile();
	void Check();

	std::vector<Shader*> shaders;
	GLuint shader_program;
	GLint uniform_location = -1;
};

