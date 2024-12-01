#pragma once

#include <glm/glm.hpp>

class MaterialGetter
{
public:
	virtual glm::vec3 GetColor() = 0;
	virtual float GetSpecular() = 0;
	virtual float GetAmbient() = 0;
	virtual float GetDiffuse() = 0;
};

class Material : public MaterialGetter
{
public:
	Material();
	glm::vec3 GetColor() override;
	float GetSpecular() override;
	float GetAmbient() override;
	float GetDiffuse() override;

	Material* SetColor(glm::vec3 color);
	Material* SetSpecular(float specular);
	Material* SetAmbient(float ambient);
	Material* SetDiffuse(float diffuse);
private:
	glm::vec3 color;
	float specular;
	float diffuse;
	float ambient;
};