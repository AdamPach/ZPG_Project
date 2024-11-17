#pragma once

#include <vector>
#include <string>

#include "../transformations/Transformation.h"
#include "../abstraction/Observer.h" 
#include "../world/cameras/Camera.h"
#include "uniforms/UniformVariableVec3.h"
#include "uniforms/UniformVariableMat4.h"
#include "uniforms/UniformVariableInt.h"
#include "../objects/materials/Material.h"

class ShaderProgram
{
public:
	ShaderProgram(GLuint shader_program, GLint uniform_transformation_location);
	virtual ~ShaderProgram();
	void Use();
	void Unuse();
	void Check();
	void SetTransformation(Transformation* transformation);
	void AddUniformVec3Variable(TypedDataProviderSubject<glm::vec3>* subject, const char* variable_name);
	void AddUniformMat4Variable(TypedDataProviderSubject<glm::mat4>* subject, const char* variable_name);
	void AddUniformIntVariable(TypedDataProviderSubject<int>* subject, const char* variable_name);
private:

	void AddTransformationUniform(std::string uniform);
	GLuint shader_program;
	GLint uniform_transformation_location = -1;

	std::vector<UniformVariable*> uniformVariables;
};

