#include "ShaderProgram.h"
#include "VertexShader.h"
#include "FragmentShader.h"

ShaderProgram::ShaderProgramBuilder* ShaderProgram::CreateBuilder()
{
	return new ShaderProgramBuilder();
}

ShaderProgram::ShaderProgram(int count_of_shaders)
{
	shaders.reserve(count_of_shaders);
}

ShaderProgram::~ShaderProgram()
{
	for(auto shader : shaders)
	{
		delete shader;
	}
}

void ShaderProgram::AddShader(Shader* shader)
{
	shaders.push_back(shader);
}

void ShaderProgram::AddTransformationUniform(std::string uniform)
{
	uniform_transformation_location = glGetUniformLocation(shader_program, uniform.c_str());
}

void ShaderProgram::AddViewUniform(std::string uniform)
{
	uniform_view_location = glGetUniformLocation(shader_program, uniform.c_str());
}

void ShaderProgram::Compile()
{
	shader_program = glCreateProgram();

	for (auto shader : shaders)
	{
		shader->AttachShader(shader_program);
	}

	glLinkProgram(shader_program);
}

void ShaderProgram::Use()
{
	glUseProgram(shader_program);

	if (uniform_view_location != -1)
	{
		glUniformMatrix4fv(uniform_view_location, 1, GL_FALSE, &view_matrix[0][0]);
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
}

void ShaderProgram::SetCamera(Camera* camera)
{
	if (this->camera != nullptr)
	{
		camera->Unsubcribe(this);
	}

	this->camera = camera;
	camera->Subcribe(this);

	Update();
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

ShaderProgram::ShaderProgramBuilder* ShaderProgram::ShaderProgramBuilder::AddVertexShader(const char* shader)
{
	shaders.push_back(new VertexShader(shader));
	
	return this;
}

ShaderProgram::ShaderProgramBuilder* ShaderProgram::ShaderProgramBuilder::AddFragmentShader(const char* shader)
{
	shaders.push_back(new FragmentShader(shader));

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

ShaderProgram* ShaderProgram::ShaderProgramBuilder::Build()
{
	ShaderProgram* shaderProgram =  new ShaderProgram(this->shaders.size());

	for (auto shader : shaders)
	{
		shaderProgram->AddShader(shader);
	}

	shaderProgram->Compile();
	shaderProgram->Check();

	if (this->transformationUniform != "")
	{
		shaderProgram->AddTransformationUniform(this->transformationUniform);
	}

	if (this->viewUniform != "")
	{
		shaderProgram->AddViewUniform(this->viewUniform);
	}

	shaders.clear();

	return shaderProgram;
}
