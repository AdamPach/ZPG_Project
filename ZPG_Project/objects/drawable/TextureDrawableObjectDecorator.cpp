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
	ShaderProgram* shader = GetShader();

	auto shaderProgram = dynamic_cast<TextureShaderProgram*>(shader);

	if (shaderProgram != nullptr)
	{
		shaderProgram->SetTexture(texture);
	}

	DrawableObjectDecorator::Draw();
}
