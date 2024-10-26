#pragma once

#include "TriangleNormalModel.h"

class SphereObject : public TriangleNormalModel
{
private:
	SphereObject();
	static SphereObject* instance;

public:
	static SphereObject* GetInstance();
};