#include "DrawableObjectDecorator.h"

#include <typeinfo>

DrawableObjectDecorator::DrawableObjectDecorator(DrawableObject* drawableObject)
{
	this->drawableObject = drawableObject;
}

DrawableObjectDecorator::~DrawableObjectDecorator()
{
	delete drawableObject;
}

void DrawableObjectDecorator::Draw()
{
	drawableObject->Draw();
}

ShaderProgram* DrawableObjectDecorator::GetShader() const
{
	return drawableObject->GetShader();
}

Transformation* DrawableObjectDecorator::GetTransformation() const
{
	return drawableObject->GetTransformation();
}

Model* DrawableObjectDecorator::GetModel() const
{
	return drawableObject->GetModel();
}

std::vector<std::pair<Subject*, std::string>> DrawableObjectDecorator::GetLightSubjects()
{
	return drawableObject->GetLightSubjects();
}