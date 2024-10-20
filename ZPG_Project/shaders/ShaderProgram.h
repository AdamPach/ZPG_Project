#pragma once

#include <vector>
#include <string>


#include "Shader.h"
#include "../transformations/Transformation.h"
#include "../abstraction/Observer.h" 
#include "../world/Camera.h"

class ShaderProgram : public Observer
{
public:
	~ShaderProgram();

	void Use();
	void Use(Transformation* transformation);
	void Update() override;
	void SetCamera(Camera* camera);

	class ShaderProgramBuilder
	{
	public:
		ShaderProgramBuilder* AddVertexShader(const char* shader);
		ShaderProgramBuilder* AddFragmentShader(const char* shader);
		ShaderProgramBuilder* AddTransformationUniform(const char* uniform);
		ShaderProgramBuilder* AddViewUniform(const char* uniform);
		ShaderProgramBuilder* AddProjectionUniform(const char* uniform);

		ShaderProgram* Build();
	private:
		std::vector<Shader*> shaders;
		std::string transformationUniform = "";
		std::string viewUniform = "";
		std::string projectionUniform = "";
	};

	static ShaderProgramBuilder* CreateBuilder();
private:
	ShaderProgram(int count_of_shaders = 2);

	void AddShader(Shader* shader);
	void AddTransformationUniform(std::string uniform);
	void AddViewUniform(std::string uniform);
	void AddProjectionUniform(std::string uniform);
	void Compile();
	void Check();

	std::vector<Shader*> shaders;

	GLuint shader_program;
	GLint uniform_transformation_location = -1, uniform_view_location = -1, uniform_projection_location = -1;

	Camera* camera = nullptr;
	glm::mat4 view_matrix = glm::mat4(1);
	glm::mat4 projection_matrix = glm::mat4(1);
};

