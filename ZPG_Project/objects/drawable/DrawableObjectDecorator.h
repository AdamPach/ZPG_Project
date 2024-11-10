#pragma once

#include "DrawableObject.h"

class DrawableObjectDecorator : public DrawableObject
{
public:
	DrawableObjectDecorator(DrawableObject* drawableObject);
	~DrawableObjectDecorator();

	void Draw() override;
	ShaderProgram* GetShader() const override;
	Transformation* GetTransformation() const override;
	Model* GetModel() const override;

	template <typename T>
	bool IsDecoratedBy();
protected:
	DrawableObject* drawableObject;
};