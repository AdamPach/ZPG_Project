#pragma once

#include "Model.h"

class TriangleNormalModel : public Model
{
public:
	TriangleNormalModel(float* points, int length);
	~TriangleNormalModel();
	virtual void DrawModel();
};

