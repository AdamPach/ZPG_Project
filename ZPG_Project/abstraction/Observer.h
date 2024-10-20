#pragma once

#include <vector>

class Observer
{
public:
	virtual void Update() = 0;
};

class Subject
{
public:
	virtual void Subcribe(Observer* observer);
	virtual void Unsubcribe(Observer* observer);
protected:
	virtual void Notify();
private:
	std::vector<Observer*> observers;
};