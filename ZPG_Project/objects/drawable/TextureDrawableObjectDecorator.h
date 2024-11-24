#pragma once

#include "DrawableObjectDecorator.h"
#include "../textures/Texture.h"

class TextureDrawableObjectDecorator : public DrawableObjectDecorator
{
public:
	TextureDrawableObjectDecorator(DrawableObject* drawableObject, Texture * texture);

	void Draw() override;
private:
	Texture* texture;
};