#include "Transformation.h"

Transformation::Transformation(TransformationComposite* container)
{
	transformationPartContainer = container;
}

Transformation::~Transformation()
{
	delete transformationPartContainer;
}

void Transformation::AddPart(TransformationBasic* part)
{
	transformationPartContainer->AddTransformation(part);
}

glm::mat4 Transformation::GetTransformationMatrix()
{
	return transformationPartContainer->GetMatrix();
}
