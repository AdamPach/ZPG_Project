#include "Material.h"

Material::Material()
{
	color = glm::vec3(0.5f, 0.5f, 0.5f);
	specular = 0.5f;
	diffuse = 0.5f;
	ambient = 0.1f;
}

glm::vec3 Material::GetColor()
{
	return color;
}

float Material::GetSpecular()
{
	return specular;
}

float Material::GetDiffuse()
{
	return diffuse;
}

float Material::GetAmbient()
{
	return ambient;
}

Material* Material::SetColor(glm::vec3 color)
{
	this->color = color;

	return this;
}

Material* Material::SetSpecular(float specular)
{
	this->specular = specular;
	return this;
}

Material* Material::SetDiffuse(float diffuse)
{
	this->diffuse = diffuse;
	return this;
}

Material* Material::SetAmbient(float ambient)
{
	this->ambient = ambient;
	return this;
}
