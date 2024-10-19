#pragma once

#include <vector>

#include "TransformationBasic.h"

class TransformationComposite : public TransformationBasic
{
public:
	TransformationComposite();
	void AddTransformation(TransformationBasic* transformationPart);
	void RemoveTransformation(TransformationBasic* transformationPart);
	glm::mat4 GetMatrix() override;

private:
	std::vector<TransformationBasic*> transformationParts;
};

