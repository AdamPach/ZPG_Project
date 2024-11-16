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

void ShaderProgram::AddMaterialColorUniform(std::string uniform)
{
	uniform_materialColor_location = glGetUniformLocation(shader_program, uniform.c_str());
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

void ShaderProgram::SetMaterial(Material* material)
{
	glm::vec3 color = material->GetColor();

	if (uniform_materialColor_location != -1)
	{
		glProgramUniform3f(shader_program, uniform_materialColor_location, color.x, color.y, color.z);
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

	if (this->materialColorUniform != "")
	{
		shaderProgram->AddMaterialColorUniform(this->materialColorUniform);
	}

	vertexShaderFileName = "";
	fragmentShaderFileName = "";

	transformationUniform = "";
	materialColorUniform = "";

	return shaderProgram;
}
