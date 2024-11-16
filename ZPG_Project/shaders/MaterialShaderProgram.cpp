#include "MaterialShaderProgram.h"

MaterialShaderProgram::MaterialShaderProgram(GLuint shader_program, GLint uniform_transformation_location, GLint uniform_materialColor_location) 
	: ShaderProgram(shader_program, uniform_transformation_location)
{
	materialColorLocation = uniform_materialColor_location;
}

void MaterialShaderProgram::SetMaterial(Material* material)
{
	Use();
	if (materialColorLocation != -1)
	{
		auto color = material->GetColor();
		glUniform3f(materialColorLocation, color.x, color.y, color.z);
	}
	Unuse();
}

