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
	viewUniform = uniform;
}

void ShaderProgram::AddProjectionUniform(std::string uniform)
{
	projectionUniform = uniform;
}

void ShaderProgram::AddMaterialColorUniform(std::string uniform)
{
	uniform_materialColor_location = glGetUniformLocation(shader_program, uniform.c_str());
}

void ShaderProgram::AddUniformVec3Variable(UniformVariableSubject<glm::vec3>* subject, const char* variable_name)
{
	GLint uniform_location = glGetUniformLocation(shader_program, variable_name);

	if (uniform_location != -1)
	{
		uniformVariables.push_back(new UniformVariableVec3(subject, uniform_location));
	}
}

void ShaderProgram::AddUniformMat4Variable(UniformVariableSubject<glm::mat4>* subject, const char* variable_name)
{
	GLint uniform_location = glGetUniformLocation(shader_program, variable_name);

	if (uniform_location != -1)
	{
		uniformVariables.push_back(new UniformVariableMat4(subject, uniform_location));
	}
}

void ShaderProgram::AddUniformIntVariable(UniformVariableSubject<int>* subject, const char* variable_name)
{
	GLint uniform_location = glGetUniformLocation(shader_program, variable_name);

	if (uniform_location != -1)
	{
		uniformVariables.push_back(new UniformVariableInt(subject, uniform_location));
	}
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(shader_program);

	for (auto observer : uniformVariables)
	{
		delete observer;
	}
}

void ShaderProgram::Use()
{
	glUseProgram(shader_program);

	for(auto variable : uniformVariables)
	{
		variable->Use();
	}

	if (uniform_materialColor_location != -1)
	{
		glUniform3f(uniform_materialColor_location, materialColor.x, materialColor.y, materialColor.z);
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

void ShaderProgram::SetMaterialColor(glm::vec3 color)
{
	this->materialColor = color;
}

void ShaderProgram::SetCamera(Camera* camera)
{
	if (this->projectionUniform != "")
	{
		AddUniformMat4Variable(camera->GetProjectionSubject(), this->projectionUniform.c_str());
	}

	if (this->viewUniform != "")
	{
		AddUniformMat4Variable(camera->GetViewSubject(), this->viewUniform.c_str());
	}
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

ShaderProgram::ShaderProgramBuilder* ShaderProgram::ShaderProgramBuilder::AddMaterialColorUniform(const char* uniform)
{
	this->materialColorUniform = uniform;

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

	if (this->materialColorUniform != "")
	{
		shaderProgram->AddMaterialColorUniform(this->materialColorUniform);
	}

	vertexShaderFileName = "";
	fragmentShaderFileName = "";

	transformationUniform = "";
	viewUniform = "";
	projectionUniform = "";
	materialColorUniform = "";

	return shaderProgram;
}
