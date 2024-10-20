#pragma once

#include <vector>

#include "Scale.h"
#include "Translation.h"
#include "TransformationComposite.h"
#include "Rotation.h"

enum Axis { X, Y, Z };

class TransformationsBuilder
{
public:
	TransformationsBuilder* AddScale(float scale);
	TransformationsBuilder* AddTranslation(float x_move, float y_move, float z_move);
	TransformationsBuilder* AddRotation(float angle, Axis axis);
	TransformationsBuilder* AddTransformation(TransformationBasic* part);

	TransformationsBuilder* Clear();

	TransformationComposite* Build();
private:
	std::vector<TransformationBasic*> transformations;
};

