#pragma once

#include "Subject.h"

template <typename T>
class TypedDataProviderSubject : public Subject
{
public:
	virtual T GetValue() = 0;
protected:
	T value;
};