#pragma once

#include "DrawableObjectDecorator.h"
#include "../../world/lights/Light.h"

class LightDrawableObjectDecorator : public DrawableObjectDecorator
{
public:
	LightDrawableObjectDecorator(DrawableObject* drawableObject, Light* light);
	~LightDrawableObjectDecorator();
	void Draw() override;
	std::vector<std::pair<UniformVariableSubject<glm::vec3>*, std::string>> GetLightSubjects() override;
private:
	Light* light;
};