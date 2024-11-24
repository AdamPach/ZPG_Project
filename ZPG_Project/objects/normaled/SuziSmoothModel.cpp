#include "SuziSmoothModel.h"
#include "../models/suzi_smooth.h"

SuziSmoothModel::SuziSmoothModel() : TriangleNormalModel(suziSmooth, sizeof(suziSmooth))
{
}

SuziSmoothModel* SuziSmoothModel::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SuziSmoothModel();
	}

	return instance;
}

SuziSmoothModel* SuziSmoothModel::instance = nullptr;
