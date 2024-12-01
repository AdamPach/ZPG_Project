#include "SuziFlatModel.h"
#include "../../assets/models/suzi_flat.h"

SuziFlatModel::SuziFlatModel() : TriangleNormalModel(suziFlat, sizeof(suziFlat))
{
}

SuziFlatModel* SuziFlatModel::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SuziFlatModel();
	}

	return instance;
}

SuziFlatModel* SuziFlatModel::instance = nullptr;
