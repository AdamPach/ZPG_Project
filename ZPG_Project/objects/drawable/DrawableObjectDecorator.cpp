#include "DrawableObjectDecorator.h"

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
