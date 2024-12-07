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
	std::vector<std::pair<Subject*, std::string>> GetLightSubjects() override;
	void SetId(int id) override;
	int GetId() const override;

protected:
	DrawableObject* drawableObject;
};