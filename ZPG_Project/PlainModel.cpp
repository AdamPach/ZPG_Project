#include "PlainModel.h"
#include "plain.h"

PlainModel::PlainModel() : TriangleNormalModel(plain, sizeof(plain))
{

}

PlainModel* PlainModel::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new PlainModel();
	}

	return instance;
}


PlainModel* PlainModel::instance = nullptr;