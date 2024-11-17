#include "SpotLightCutOffSubject.h"

SpotLightCutOffSubject::SpotLightCutOffSubject()
{
	value = glm::cos(glm::radians(0.0f));
}

float SpotLightCutOffSubject::GetValue()
{
	return value;
}

void SpotLightCutOffSubject::SetValue(float value)
{
	this->value = glm::cos(glm::radians(value));
	Notify();
}
