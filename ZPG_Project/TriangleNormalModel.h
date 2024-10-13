#pragma once

#include "Model.h"

class TriangleNormalModel : public Model
{
public:
	~TriangleNormalModel();
	virtual void DrawModel();
protected:
	TriangleNormalModel(float* points, int length);
};

