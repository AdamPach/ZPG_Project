#include "LightDrawableObjectDecorator.h"

LightDrawableObjectDecorator::LightDrawableObjectDecorator(DrawableObject* drawableObject, Light* light) : DrawableObjectDecorator(drawableObject)
{
	this->light = light;

	UpdateLightPosition();
}

LightDrawableObjectDecorator::~LightDrawableObjectDecorator()
{
	delete light;
}

void LightDrawableObjectDecorator::Draw()
{
	UpdateLightPosition();
	
	DrawableObjectDecorator::Draw();
}

std::vector<std::pair<UniformVariableSubject<glm::vec3>*, std::string>> LightDrawableObjectDecorator::GetLightSubjects()
{
	auto subjects = DrawableObjectDecorator::GetLightSubjects();
	auto lightSubjects = light->GetSubjects();

	subjects.insert(subjects.end(), lightSubjects.begin(), lightSubjects.end());

	return subjects;
}

void LightDrawableObjectDecorator::UpdateLightPosition()
{
	glm::mat4 currentPosition = GetTransformation()->GetTransformationMatrix();

	if (currentPosition == lastPosition)
	{
		return DrawableObjectDecorator::Draw();
	}

	lastPosition = currentPosition;

	glm::vec4 modelCenterPosition = glm::vec4(GetModel()->GetModelCenter(), 1.0f);
	glm::vec4 newModelCenterPosition = lastPosition * modelCenterPosition;

	glm::vec3 lightPosition = glm::vec3(
		newModelCenterPosition.x / newModelCenterPosition.w,
		newModelCenterPosition.y / newModelCenterPosition.w,
		newModelCenterPosition.z / newModelCenterPosition.w);

	light->SetPosition(lightPosition);
}
