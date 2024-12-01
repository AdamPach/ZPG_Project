#pragma once

#include "ShaderProgram.h"

class MaterialShaderProgram : public ShaderProgram
{
public:
	MaterialShaderProgram(GLuint shader_program, GLint uniform_transformation_location);
	void SetMaterial(MaterialGetter* material);
	void UnsetMaterial();

	void SetColorLocation(GLint colorLocation);
	void SetAmbientLocation(GLint ambientLocation);
	void SetDiffuseLocation(GLint diffuseLocation);
	void SetSpecularLocation(GLint specularLocation);
private:
	GLint materialColorLocation = -1;
	GLint materialAmbientLocation = -1;
	GLint materialDiffuseLocation = -1;
	GLint materialSpecularLocation = -1;
};
