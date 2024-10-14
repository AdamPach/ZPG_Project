#include "TransformationPartContainer.h"

TransformationPartContainer::~TransformationPartContainer()
{
	for (TransformationPart* transformationPart : transformationParts)
	{
		delete transformationPart;
	}
}

void TransformationPartContainer::AddTransformationPartAtStart(TransformationPart* transformationPart)
{
	transformationParts.insert(transformationParts.begin(), transformationPart);
}

void TransformationPartContainer::AddTransformationPartAtEnd(TransformationPart* transformationPart)
{
	transformationParts.push_back(transformationPart);
}

void TransformationPartContainer::RemoveTransformationPart(TransformationPart* transformationPart)
{
	transformationParts.erase(std::remove(transformationParts.begin(), transformationParts.end(), transformationPart), transformationParts.end());
}

glm::mat4 TransformationPartContainer::GetTransformation(glm::mat4 M)
{
	glm::mat4 result = M;

	for (TransformationPart* transformationPart : transformationParts)
	{
		result = transformationPart->GetTransformation(result);
	}
	return result;
}
