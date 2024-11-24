#pragma once

#include "../abstraction/TriangleNormalModel.h"

class TreeModel : public TriangleNormalModel
{
private:
	TreeModel();
	static TreeModel* instance;
public:
	static TreeModel* GetInstance();
};

