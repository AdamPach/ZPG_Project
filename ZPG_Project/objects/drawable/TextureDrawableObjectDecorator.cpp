#include "TextureDrawableObjectDecorator.h"
#include <SOIL.h>
#include <iostream>
#include "../../shaders/TextureShaderProgram.h"

TextureDrawableObjectDecorator::TextureDrawableObjectDecorator(DrawableObject* drawableObject, Texture* texture)
	: DrawableObjectDecorator(drawableObject)
{
	this->texture = texture;
}

void TextureDrawableObjectDecorator::Draw()
{
	auto shaderProgram = dynamic_cast<TextureShaderProgram*>(GetShader());

	if (shaderProgram != nullptr)
	{
		shaderProgram->SetTexture(texture);
	}

	DrawableObjectDecorator::Draw();
}
