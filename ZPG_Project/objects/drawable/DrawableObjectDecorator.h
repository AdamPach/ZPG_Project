#pragma once

#include "DrawableObject.h"

class DrawableObjectDecorator : public DrawableObject
{
public:
	DrawableObjectDecorator(DrawableObject* drawableObject);
	~DrawableObjectDecorator();
	void Draw() override;
	ShaderProgram* GetShader() const override;
protected:
	DrawableObject* drawableObject;
};