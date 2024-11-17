#include "SpotLightOuterCutOffSubject.h"

SpotLightOuterCutOffSubject::SpotLightOuterCutOffSubject()
{
	value = glm::cos(glm::radians(0.0f));
}

void SpotLightOuterCutOffSubject::SetValue(float value)
{
	this->value = glm::cos(glm::radians(value));
	Notify();
}

float SpotLightOuterCutOffSubject::GetValue()
{
	return value;
}