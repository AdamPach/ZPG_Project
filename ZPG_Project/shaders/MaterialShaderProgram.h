#pragma once

#include "ShaderProgram.h"

class MaterialShaderProgram : public ShaderProgram
{
public:
	MaterialShaderProgram(GLuint shader_program, GLint uniform_transformation_location, GLint uniform_materialColor_location);
	void SetMaterial(Material* material);
private:
	GLint materialColorLocation;
};
