#include "ShaderProgram.h"
#include "ShaderLoader.h"


ShaderProgram::ShaderProgramBuilder* ShaderProgram::CreateBuilder()
{
	return new ShaderProgramBuilder();
}

ShaderProgram::ShaderProgram()
{
}

void ShaderProgram::AddTransformationUniform(std::string uniform)
{
	uniform_transformation_location = glGetUniformLocation(shader_program, uniform.c_str());
}

void ShaderProgram::AddViewUniform(std::string uniform)
{
	uniform_view_location = glGetUniformLocation(shader_program, uniform.c_str());
}

void ShaderProgram::AddProjectionUniform(std::string uniform)
{
	uniform_projection_location = glGetUniformLocation(shader_program, uniform.c_str());
}

void ShaderProgram::Use()
{
	glUseProgram(shader_program);

	if (uniform_view_location != -1)
	{
		glUniformMatrix4fv(uniform_view_location, 1, GL_FALSE, &view_matrix[0][0]);
	}

	if (uniform_projection_location != -1)
	{
		glUniformMatrix4fv(uniform_projection_location, 1, GL_FALSE, &projection_matrix[0][0]);
	}
}

void ShaderProgram::Use(Transformation* transformation)
{
	Use();

	if (uniform_transformation_location != -1)
	{
		glUniformMatrix4fv(uniform_transformation_location, 1, GL_FALSE, &transformation->GetTransformationMatrix()[0][0]);
	}
}

void ShaderProgram::Update()
{
	view_matrix = camera->GetViewMatrix();
	projection_matrix = camera->GetProjectionMatrix();
}

void ShaderProgram::SetCamera(Camera* camera)
{
	if (this->camera != nullptr)
	{
		camera->Unsubcribe(this);
	}

	this->camera = camera;
	camera->Subcribe(this);
}

void ShaderProgram::Check()
{
	GLint status;
	glGetProgramiv(shader_program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shader_program, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shader_program, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

ShaderProgram::ShaderProgramBuilder* ShaderProgram::ShaderProgramBuilder::AddVertexShader(const char* shader_file_name)
{
	vertexShaderFileName = shader_file_name;

	return this;
}

ShaderProgram::ShaderProgramBuilder* ShaderProgram::ShaderProgramBuilder::AddFragmentShader(const char* shader_file_name)
{
	fragmentShaderFileName = shader_file_name;

	return this;
}

ShaderProgram::ShaderProgramBuilder* ShaderProgram::ShaderProgramBuilder::AddTransformationUniform(const char* uniform)
{
	this->transformationUniform = uniform;

	return this;
}

ShaderProgram::ShaderProgramBuilder * ShaderProgram::ShaderProgramBuilder::AddViewUniform(const char* uniform)
{
	this->viewUniform = uniform;

	return this;
}

ShaderProgram::ShaderProgramBuilder* ShaderProgram::ShaderProgramBuilder::AddProjectionUniform(const char* uniform)
{
	this->projectionUniform = uniform;

	return this;
}

ShaderProgram* ShaderProgram::ShaderProgramBuilder::Build()
{
	ShaderProgram* shaderProgram =  new ShaderProgram();
	ShaderLoader loader;

	shaderProgram->shader_program = loader.loadShader(
		(SHADER_PATH + vertexShaderFileName).c_str(),
		(SHADER_PATH + fragmentShaderFileName).c_str());

	shaderProgram->Check();

	if (this->transformationUniform != "")
	{
		shaderProgram->AddTransformationUniform(this->transformationUniform);
	}

	if (this->viewUniform != "")
	{
		shaderProgram->AddViewUniform(this->viewUniform);
	}

	if (this->projectionUniform != "")
	{
		shaderProgram->AddProjectionUniform(this->projectionUniform);
	}

	vertexShaderFileName = "";
	fragmentShaderFileName = "";

	transformationUniform = "";
	viewUniform = "";
	projectionUniform = "";

	return shaderProgram;
}
