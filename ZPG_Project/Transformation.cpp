#include "Transformation.h"

Transformation::Transformation()
{
	M = nullptr;
}

Transformation::Transformation(std::vector<TransformationPart*> parts)
{
	M = nullptr;
	this->parts = parts;
}

Transformation::~Transformation()
{
	for (auto part : parts)
	{
		delete part;
	}
}

void Transformation::AddPart(TransformationPart* part)
{
	parts.push_back(part);
}

glm::mat4 Transformation::GetTransformation()
{
	if (M != nullptr)
	{
		return glm::mat4(*M);
	}

	M = new glm::mat4(1.0f);

	for (auto part : parts)
	{
		*M = part->GetTransformation(*M);
	}

	return glm::mat4(*M);
}
