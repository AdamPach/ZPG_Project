#include "TransformationComposite.h"

void TransformationComposite::AddTransformation(TransformationBasic* transformationPart)
{
	transformationParts.push_back(transformationPart);
}

void TransformationComposite::RemoveTransformation(TransformationBasic* transformationPart)
{
	transformationParts.erase(std::remove(transformationParts.begin(), transformationParts.end(), transformationPart), transformationParts.end());
}

glm::mat4 TransformationComposite::GetTransformation(glm::mat4 M)
{
	glm::mat4 result = M;

	for (TransformationBasic* transformationPart : transformationParts)
	{
		result = transformationPart->GetTransformation(result);
	}
	return result;
}
