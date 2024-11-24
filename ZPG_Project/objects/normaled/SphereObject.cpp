#include "SphereObject.h"

#include "../models/sphere.h"

SphereObject::SphereObject() : TriangleNormalModel(sphere, sizeof(sphere))
{
}

SphereObject* SphereObject::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SphereObject();
	}

    return instance;
}

SphereObject* SphereObject::instance = nullptr;