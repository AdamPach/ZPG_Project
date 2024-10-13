#include "TransformationsCollectionBuilder.h"

TransformationsCollectionBuilder* TransformationsCollectionBuilder::AddScalePart(float scale)
{
	transformations.push_back(new ScalePart(glm::vec3(scale)));

	return this;
}

TransformationsCollectionBuilder* TransformationsCollectionBuilder::AddTranslationPart(float x_move, float y_move, float z_move)
{
	transformations.push_back(new TranslationPart(glm::vec3(x_move, y_move, z_move)));

	return this;
}

TransformationsCollectionBuilder* TransformationsCollectionBuilder::AddRotationPart(float angle, Axis axis)
{
	glm::vec3 axisVec;
	switch (axis)
	{
	case X:
		axisVec = glm::vec3(1.0f, 0.0f, 0.0f);
		break;
	case Y:
		axisVec = glm::vec3(0.0f, 1.0f, 0.0f);
		break;
	case Z:
		axisVec = glm::vec3(0.0f, 0.0f, 1.0f);
		break;
	}
	transformations.push_back(new RotationPart(angle, axisVec));

	return this;
}

TransformationsCollectionBuilder* TransformationsCollectionBuilder::Clear()
{
	transformations.clear();

	return this;
}

std::vector<TransformationPart*> TransformationsCollectionBuilder::Build()
{
	return transformations;
}
