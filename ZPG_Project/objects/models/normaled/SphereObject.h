#pragma once

#include "../abstraction/TriangleNormalModel.h"

class SphereObject : public TriangleNormalModel
{
private:
	SphereObject();
	static SphereObject* instance;

public:
	static SphereObject* GetInstance();
};