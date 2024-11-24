#pragma once

#include "../abstraction/TriangleNormalModel.h"

class SuziSmoothModel : public TriangleNormalModel
{
private:
	SuziSmoothModel();
	static SuziSmoothModel* instance;
public:
	static SuziSmoothModel* GetInstance();
};