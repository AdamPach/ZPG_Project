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