#pragma once

#include "TriangleNormalModel.h"

class SuziFlatModel : public TriangleNormalModel
{
private:
	SuziFlatModel();
	static SuziFlatModel* instance;
public:
	static SuziFlatModel* GetInstance();
};