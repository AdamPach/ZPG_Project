#pragma once

#include "../abstraction/TriangleNormalModel.h"

class SuziFlatModel : public TriangleNormalModel
{
private:
	SuziFlatModel();
	static SuziFlatModel* instance;
public:
	static SuziFlatModel* GetInstance();
};