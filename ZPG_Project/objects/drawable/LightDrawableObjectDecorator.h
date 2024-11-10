#pragma once

#include "DrawableObjectDecorator.h"
#include "../../world/lights/Light.h"

class LightDrawableObjectDecorator : public DrawableObjectDecorator
{
public:
	LightDrawableObjectDecorator(DrawableObject* drawableObject, Light* light);
	~LightDrawableObjectDecorator();
	void Draw() override;
private:
	Light* light;
};