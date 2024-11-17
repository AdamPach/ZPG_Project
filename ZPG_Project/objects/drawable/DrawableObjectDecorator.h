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
	std::vector<std::pair<TypedDataProviderSubject<glm::vec3>*, std::string>> GetLightSubjects() override;

protected:
	DrawableObject* drawableObject;
};