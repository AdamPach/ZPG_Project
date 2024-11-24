#include "Texture.h"
#include <GL/glew.h>


Texture::Texture(int texture_unit)
{
	glActiveTexture(GL_TEXTURE0 + texture_unit);
	this->texture_unit = texture_unit;
}

Texture::~Texture()
{
}

int Texture::GetTextureUnit()
{
	return texture_unit;
}
