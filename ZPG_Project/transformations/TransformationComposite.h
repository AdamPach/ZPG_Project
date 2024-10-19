#pragma once

#include <vector>

#include "TransformationBasic.h"

class TransformationComposite : public TransformationBasic
{
public:
	void AddTransformation(TransformationBasic* transformationPart);
	void RemoveTransformation(TransformationBasic* transformationPart);
	glm::mat4 GetTransformation(glm::mat4 M);

private:
	std::vector<TransformationBasic*> transformationParts;
};

