#include "ShaderProgramBuilder.h"
#include "TextureShaderProgram.h"

ShaderProgramBuilder* ShaderProgramBuilder::AddVertexShader(const char* shader_file_name)
{
	vertexShaderFileName = shader_file_name;

	return this;
}

ShaderProgramBuilder* ShaderProgramBuilder::AddFragmentShader(const char* shader_file_name)
{
	fragmentShaderFileName = shader_file_name;

	return this;
}

ShaderProgramBuilder* ShaderProgramBuilder::AddTransformationUniform(const char* uniform)
{
	transformationUniform = uniform;

	return this;
}

ShaderProgramBuilder* ShaderProgramBuilder::AddMaterialUniform(const char* uniform)
{
	materialColorUniform = uniform;

	return this;
}

ShaderProgramBuilder* ShaderProgramBuilder::AddTextureUnitUniform(const char* uniform)
{
	textureUnitUniform = uniform;

	return this;
}

ShaderProgram* ShaderProgramBuilder::Build()
{
	ShaderLoader loader;

	GLuint program = loader.loadShader(
		(SHADER_PATH + vertexShaderFileName).c_str(),
		(SHADER_PATH + fragmentShaderFileName).c_str());

	GLint transformationUniformLocation = glGetUniformLocation(program, transformationUniform.c_str());
	GLint materialColorUniformLocation = glGetUniformLocation(program, materialColorUniform.c_str());
	GLint textureUnitUniformLocation = glGetUniformLocation(program, textureUnitUniform.c_str());

	vertexShaderFileName = "";
	fragmentShaderFileName = "";
	transformationUniform = "";
	materialColorUniform = "";
	textureUnitUniform = "";

	ShaderProgram* shaderProgram;

	if (materialColorUniformLocation != -1)
	{
		if (textureUnitUniformLocation != -1)
		{
			shaderProgram = new TextureShaderProgram(program, transformationUniformLocation, materialColorUniformLocation, textureUnitUniformLocation);
		}
		else
		{
			shaderProgram = new MaterialShaderProgram(program, transformationUniformLocation, materialColorUniformLocation);
		}
	}
	else
	{
		shaderProgram = new ShaderProgram(program, transformationUniformLocation);
	}

	shaderProgram->Check();

	return shaderProgram;
}
