#include "BushesModel.h"
#include "bushes.h"

BushesModel::BushesModel() : TriangleNormalModel(bushes, sizeof(bushes))
{
}

BushesModel* BushesModel::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BushesModel();
	}

	return instance;
}

BushesModel* BushesModel::instance = nullptr;