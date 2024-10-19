#include "TransformationsBuilder.h"

TransformationsBuilder* TransformationsBuilder::AddScalePart(float scale)
{
	transformations.push_back(new Scale(glm::vec3(scale)));

	return this;
}

TransformationsBuilder* TransformationsBuilder::AddTranslationPart(float x_move, float y_move, float z_move)
{
	transformations.push_back(new Translation(glm::vec3(x_move, y_move, z_move)));

	return this;
}

TransformationsBuilder* TransformationsBuilder::AddRotationPart(float angle, Axis axis)
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
	
	transformations.push_back(new Rotation(angle, axisVec));

	return this;
}

TransformationsBuilder* TransformationsBuilder::AddTransformation(TransformationBasic* part)
{
	transformations.push_back(part);

	return this;
}

TransformationsBuilder* TransformationsBuilder::Clear()
{
	transformations.clear();

	return this;
}

TransformationComposite* TransformationsBuilder::Build()
{
	TransformationComposite* container = new TransformationComposite();

	for (TransformationBasic* transformation : transformations)
	{
		container->AddTransformation(transformation);
	}

	transformations.clear();

	return container;
}
