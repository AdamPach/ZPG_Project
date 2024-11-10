#include "LightDrawableObjectDecorator.h"

LightDrawableObjectDecorator::LightDrawableObjectDecorator(DrawableObject* drawableObject, Light* light) : DrawableObjectDecorator(drawableObject)
{
	this->light = light;
}

LightDrawableObjectDecorator::~LightDrawableObjectDecorator()
{
	delete light;
}

void LightDrawableObjectDecorator::Draw()
{
	//light->SetPosition(GetTransformation()->GetTransformationMatrix());
	DrawableObjectDecorator::Draw();
}

std::vector<std::pair<UniformVariableSubject<glm::vec3>*, std::string>> LightDrawableObjectDecorator::GetLightSubjects()
{
	auto subjects = DrawableObjectDecorator::GetLightSubjects();
	auto lightSubjects = light->GetSubjects();

	subjects.insert(subjects.end(), lightSubjects.begin(), lightSubjects.end());

	return subjects;
}
