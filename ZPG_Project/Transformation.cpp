#include "Transformation.h"

Transformation::Transformation()
{
	M = nullptr;
}

Transformation::Transformation(TransformationPartContainer* container)
{
	M = nullptr;
	transformationPartContainer = container;
}

Transformation::~Transformation()
{
	delete transformationPartContainer;
}

void Transformation::AddPart(TransformationPart* part)
{
	transformationPartContainer->AddTransformationPartAtEnd(part);
}

glm::mat4 Transformation::GetTransformation()
{
	if (M != nullptr)
	{
		return glm::mat4(*M);
	}

	M = new glm::mat4(1.0f);

	if (transformationPartContainer != nullptr)
	{
		*M = transformationPartContainer->GetTransformation(*M);
	}

	return glm::mat4(*M);
}
