#pragma once

#include <vector>
#include <string>

#include "../transformations/Transformation.h"
#include "../abstraction/Observer.h" 
#include "../world/cameras/Camera.h"
#include "UniformVariableVec3.h"

class ShaderProgram : public Observer
{
public:
	~ShaderProgram();
	void Use();
	void Use(Transformation* transformation);
	void Update() override;
	void SetCamera(Camera* camera);
	void AddUniformVe3Variable(UniformVariableSubject<glm::vec3>* subject, const char* variable_name);

	class ShaderProgramBuilder
	{
	public:
		ShaderProgramBuilder* AddVertexShader(const char* shader_file_name);
		ShaderProgramBuilder* AddFragmentShader(const char* shader_file_name);
		ShaderProgramBuilder* AddTransformationUniform(const char* uniform);
		ShaderProgramBuilder* AddViewUniform(const char* uniform);
		ShaderProgramBuilder* AddProjectionUniform(const char* uniform);

		ShaderProgram* Build();
	private:
		std::string vertexShaderFileName = "";
		std::string fragmentShaderFileName = "";

		std::string transformationUniform = "";
		std::string viewUniform = "";
		std::string projectionUniform = "";

		const std::string SHADER_PATH = GPU_SHADER_PATH;
	};

	static ShaderProgramBuilder* CreateBuilder();
private:
	ShaderProgram();

	void AddTransformationUniform(std::string uniform);
	void AddViewUniform(std::string uniform);
	void AddProjectionUniform(std::string uniform);

	void Check();

	GLuint shader_program;
	GLint uniform_transformation_location = -1, uniform_view_location = -1, uniform_projection_location = -1;

	Camera* camera = nullptr;
	glm::mat4 view_matrix = glm::mat4(1);
	glm::mat4 projection_matrix = glm::mat4(1);
	std::vector<UniformVariableVec3*> uniformVec3Variables;
};

