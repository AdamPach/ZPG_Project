#include "TransformationComposite.h"

TransformationComposite::TransformationComposite()
{
	transformationMatrix = glm::mat4(1.0f);
}

void TransformationComposite::AddTransformation(TransformationBasic* transformationPart)
{
	transformationParts.push_back(transformationPart);
}

void TransformationComposite::RemoveTransformation(TransformationBasic* transformationPart)
{
	transformationParts.erase(std::remove(transformationParts.begin(), transformationParts.end(), transformationPart), transformationParts.end());
}

glm::mat4 TransformationComposite::GetMatrix()
{
	if (transformationMatrix != glm::mat4(1.0f))
	{
		return transformationMatrix;
	}

	glm::mat4 matrix = glm::mat4(1.0f);

	for (TransformationBasic* transformationPart : transformationParts)
	{
		matrix = transformationPart->GetMatrix() * matrix;
	}

	transformationMatrix = matrix;

	return transformationMatrix;
}