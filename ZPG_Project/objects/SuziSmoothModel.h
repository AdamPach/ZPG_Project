#pragma once

#include "TriangleNormalModel.h"

class SuziSmoothModel : public TriangleNormalModel
{
private:
	SuziSmoothModel();
	static SuziSmoothModel* instance;
public:
	static SuziSmoothModel* GetInstance();
};