#pragma once

#include <vector>

#include "TransformationPart.h"

class TransformationPartContainer : public TransformationPart
{
public:
	~TransformationPartContainer();
	void AddTransformationPartAtStart(TransformationPart* transformationPart);
	void AddTransformationPartAtEnd(TransformationPart* transformationPart);
	void RemoveTransformationPart(TransformationPart* transformationPart);
	glm::mat4 GetTransformation(glm::mat4 M);

private:
	std::vector<TransformationPart*> transformationParts;
};

