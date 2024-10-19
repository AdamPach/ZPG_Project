#pragma once

#include <vector>

#include "Scale.h"
#include "Translation.h"
#include "TransformationComposite.h"
#include "Rotation.h"

class TransformationsBuilder
{
public:
	enum Axis { X, Y, Z };

	TransformationsBuilder* AddScalePart(float scale);
	TransformationsBuilder* AddTranslationPart(float x_move, float y_move, float z_move);
	TransformationsBuilder* AddRotationPart(float angle, Axis axis);
	TransformationsBuilder* AddTransformation(TransformationBasic* part);

	TransformationsBuilder* Clear();

	TransformationComposite* Build();
private:
	std::vector<TransformationBasic*> transformations;
};

