#include "TreeModel.h"
#include "tree.h"

TreeModel::TreeModel() : TriangleNormalModel(tree, sizeof(tree))
{
}

TreeModel* TreeModel::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new TreeModel();
	}

	return instance;
}

TreeModel* TreeModel::instance = nullptr;