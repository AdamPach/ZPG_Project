#include "LightSource.h"

LightSource::LightSource()
{
	x = 0;
	y = 0;
	z = 0;
}

void LightSource::SetPosition(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	Notify();
}

glm::vec3 LightSource::GetValue()
{
	return glm::vec3(x, y, z);
}
