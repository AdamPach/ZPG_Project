#pragma once

#include "Subject.h"

template <typename T>
class UniformVariableSubject : public Subject
{
public:
	virtual T GetValue() = 0;
	virtual void SetValue(T value) = 0;
protected:
	T value;
};