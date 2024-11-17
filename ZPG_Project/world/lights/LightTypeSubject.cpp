#include "LightTypeSubject.h"

LightTypeSubject::LightTypeSubject()
{
	value = 0;
}

int LightTypeSubject::GetValue()
{
	return value;
}

void LightTypeSubject::SetValue(int value)
{
	this->value = value;
	Notify();
}
