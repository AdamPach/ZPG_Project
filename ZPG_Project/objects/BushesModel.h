#pragma once

#include "TriangleNormalModel.h"

class BushesModel : public TriangleNormalModel
{
private:
	BushesModel();
	static BushesModel* instance;
public:
	static BushesModel* GetInstance();
};
