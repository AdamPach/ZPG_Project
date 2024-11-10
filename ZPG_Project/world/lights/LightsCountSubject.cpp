#include "LightsCountSubject.h"

LightsCountSubject::LightsCountSubject()
{
	value = 0;
}

int LightsCountSubject::GetValue()
{
	return value;
}

void LightsCountSubject::SetValue(int value)
{
	this->value = value;
	Notify();
}
