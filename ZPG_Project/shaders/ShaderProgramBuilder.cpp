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
	GLint materialColorUniformLocation = glGetUniformLocation(program, std::string(materialColorUniform).append(".").append(DEFAULT_MATERIAL_COLOR_NAME).c_str());
	GLint materialSpecularUniformLocation = glGetUniformLocation(program, std::string(materialColorUniform).append(".").append(DEFAULT_MATERIAL_SPECULAR_NAME).c_str());
	GLint materialAmbientUniformLocation = glGetUniformLocation(program, std::string(materialColorUniform).append(".").append(DEFAULT_MATERIAL_AMBIENT_NAME).c_str());
	GLint materialDiffuseUniformLocation = glGetUniformLocation(program, std::string(materialColorUniform).append(".").append(DEFAULT_MATERIAL_DIFFUSE_NAME).c_str());
	GLint textureUnitUniformLocation = glGetUniformLocation(program, textureUnitUniform.c_str());

	vertexShaderFileName = "";
	fragmentShaderFileName = "";
	transformationUniform = "";
	materialColorUniform = "";
	textureUnitUniform = "";

	ShaderProgram* shaderProgram;

	if (textureUnitUniformLocation != -1)
	{
		auto materialShader = new TextureShaderProgram(program, transformationUniformLocation, textureUnitUniformLocation);
		materialShader->SetColorLocation(materialColorUniformLocation);
		materialShader->SetAmbientLocation(materialAmbientUniformLocation);
		materialShader->SetDiffuseLocation(materialDiffuseUniformLocation);
		materialShader->SetSpecularLocation(materialSpecularUniformLocation);
		shaderProgram = materialShader;
	}
	else if (materialColorUniformLocation != -1 || materialAmbientUniformLocation != -1 || materialDiffuseUniformLocation != -1 || materialSpecularUniformLocation != -1)
	{
		auto materialShader = new MaterialShaderProgram(program, transformationUniformLocation);
		materialShader->SetColorLocation(materialColorUniformLocation);
		materialShader->SetAmbientLocation(materialAmbientUniformLocation);
		materialShader->SetDiffuseLocation(materialDiffuseUniformLocation);
		materialShader->SetSpecularLocation(materialSpecularUniformLocation);
		shaderProgram = materialShader;
	}
	else
	{
		shaderProgram = new ShaderProgram(program, transformationUniformLocation);
	}

	shaderProgram->Check();

	return shaderProgram;
}
