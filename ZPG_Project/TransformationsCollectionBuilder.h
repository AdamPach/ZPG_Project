#pragma once

#include <vector>

#include "ScalePart.h"
#include "TranslationPart.h"
#include "TransformationPartContainer.h"
#include "RotationPart.h"

class TransformationsCollectionBuilder
{
public:
	enum Axis { X, Y, Z };

	TransformationsCollectionBuilder* AddScalePart(float scale);
	TransformationsCollectionBuilder* AddTranslationPart(float x_move, float y_move, float z_move);
	TransformationsCollectionBuilder* AddRotationPart(float angle, Axis axis);
	TransformationsCollectionBuilder* AddPart(TransformationPart* part);

	TransformationsCollectionBuilder* Clear();

	TransformationPartContainer* Build();
private:
	std::vector<TransformationPart*> transformations;
};

