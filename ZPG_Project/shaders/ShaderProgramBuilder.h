#pragma once

#include <string>

#include "ShaderLoader.h"
#include "ShaderProgram.h"
#include "MaterialShaderProgram.h"

class ShaderProgramBuilder
{
public:
	ShaderProgramBuilder* AddVertexShader(const char* shader_file_name);
	ShaderProgramBuilder* AddFragmentShader(const char* shader_file_name);
	ShaderProgramBuilder* AddTransformationUniform(const char* uniform);
	ShaderProgramBuilder* AddMaterialUniform(const char* uniform);
	ShaderProgramBuilder* AddTextureUnitUniform(const char* uniform);

	ShaderProgram* Build();
private:
	std::string vertexShaderFileName = "";
	std::string fragmentShaderFileName = "";

	std::string transformationUniform = "";
	std::string materialColorUniform = "";
	std::string textureUnitUniform = "";

	const std::string SHADER_PATH = GPU_SHADER_PATH;
};