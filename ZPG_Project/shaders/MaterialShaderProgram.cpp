#include "MaterialShaderProgram.h"

MaterialShaderProgram::MaterialShaderProgram(GLuint shader_program, GLint uniform_transformation_location) : ShaderProgram(shader_program, uniform_transformation_location)
{
}

void MaterialShaderProgram::SetMaterial(MaterialGetter* material)
{
	Use();

	if (materialColorLocation != -1)
	{
		auto color = material->GetColor();
		glUniform3f(materialColorLocation, color.x, color.y, color.z);
	}

	if (materialAmbientLocation != -1)
	{
		auto ambient = material->GetAmbient();
		glUniform1f(materialAmbientLocation, ambient);
	}

	if (materialDiffuseLocation != -1)
	{
		auto diffuse = material->GetDiffuse();
		glUniform1f(materialDiffuseLocation, diffuse);
	}

	if (materialSpecularLocation != -1)
	{
		auto specular = material->GetSpecular();
		glUniform1f(materialSpecularLocation, specular);
	}

	Unuse();
}

void MaterialShaderProgram::UnsetMaterial()
{
	Use();

	if (materialColorLocation != -1)
	{
		glUniform3f(materialColorLocation, 0, 0, 0);
	}
	if (materialAmbientLocation != -1)
	{
		glUniform1f(materialAmbientLocation, 0);
	}
	if (materialDiffuseLocation != -1)
	{
		glUniform1f(materialDiffuseLocation, 0);
	}
	if (materialSpecularLocation != -1)
	{
		glUniform1f(materialSpecularLocation, 0);
	}

	Unuse();
}

void MaterialShaderProgram::SetColorLocation(GLint colorLocation)
{
	materialColorLocation = colorLocation;
}

void MaterialShaderProgram::SetAmbientLocation(GLint ambientLocation)
{
	materialAmbientLocation = ambientLocation;
}

void MaterialShaderProgram::SetDiffuseLocation(GLint diffuseLocation)
{
	materialDiffuseLocation = diffuseLocation;
}

void MaterialShaderProgram::SetSpecularLocation(GLint specularLocation)
{
	materialSpecularLocation = specularLocation;
}

