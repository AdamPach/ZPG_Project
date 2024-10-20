#include "Observer.h"

void Subject::Subcribe(Observer* observer)
{
	observers.push_back(observer);
}

void Subject::Unsubcribe(Observer* observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::Notify()
{
	for (Observer* observer : observers)
	{
		observer->Update();
	}
}
