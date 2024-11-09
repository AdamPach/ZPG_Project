#include "Material.h"

Material::Material(glm::vec3 color)
{
	this->color = color;
}

glm::vec3 Material::GetColor()
{
	return color;
}
