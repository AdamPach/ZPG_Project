#pragma once

#include "Observer.h"

class Subject
{
public:
	virtual void Subcribe(Observer* observer);
	virtual void Unsubcribe(Observer* observer);
	virtual void Notify();
private:
	std::vector<Observer*> observers;
};