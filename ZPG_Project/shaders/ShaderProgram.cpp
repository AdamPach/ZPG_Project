#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(GLuint shader_program, GLint uniform_transformation_location)
{
	this->shader_program = shader_program;
	this->uniform_transformation_location = uniform_transformation_location;
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(shader_program);

	for (auto observer : uniformVariables)
	{
		delete observer;
	}
}

void ShaderProgram::AddTransformationUniform(std::string uniform)
{
	uniform_transformation_location = glGetUniformLocation(shader_program, uniform.c_str());
}

void ShaderProgram::AddUniformVec3Variable(UniformVariableSubject<glm::vec3>* subject, const char* variable_name)
{
	GLint uniform_location = glGetUniformLocation(shader_program, variable_name);

	if (uniform_location != -1)
	{
		uniformVariables.push_back(new UniformVariableVec3(subject, shader_program, uniform_location));
	}
}

void ShaderProgram::AddUniformMat4Variable(UniformVariableSubject<glm::mat4>* subject, const char* variable_name)
{
	GLint uniform_location = glGetUniformLocation(shader_program, variable_name);

	if (uniform_location != -1)
	{
		uniformVariables.push_back(new UniformVariableMat4(subject, shader_program, uniform_location));
	}
}

void ShaderProgram::AddUniformIntVariable(UniformVariableSubject<int>* subject, const char* variable_name)
{
	GLint uniform_location = glGetUniformLocation(shader_program, variable_name);

	if (uniform_location != -1)
	{
		uniformVariables.push_back(new UniformVariableInt(subject, shader_program, uniform_location));
	}
}

void ShaderProgram::Use()
{
	glUseProgram(shader_program);
}

void ShaderProgram::Unuse()
{
	glUseProgram(0);
}

void ShaderProgram::SetTransformation(Transformation* transformation)
{
	if (uniform_transformation_location != -1)
	{
		glProgramUniformMatrix4fv(shader_program, uniform_transformation_location, 1, GL_FALSE, &transformation->GetTransformationMatrix()[0][0]);
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