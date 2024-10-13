#include "Transformation.h"

Transformation::Transformation(GLint unimform_id)
{
	this->unimform_id = unimform_id;
}

Transformation::Transformation(GLint unimform_id, std::vector<TransformationPart*> parts)
{
	this->unimform_id = unimform_id;

	for (auto part : parts)
	{
		AddPart(part);
	}
}

void Transformation::AddPart(TransformationPart* part)
{
	parts.push_back(part);
}

void Transformation::Use()
{
	glm::mat4 M = glm::mat4(1.0f);

	for (auto part : parts)
	{
		M = part->GetTransformation(M);
	}

	glUniformMatrix4fv(unimform_id, 1, GL_FALSE, &M[0][0]);
}
