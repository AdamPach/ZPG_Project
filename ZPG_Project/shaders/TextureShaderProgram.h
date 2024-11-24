#pragma once

#include "MaterialShaderProgram.h"
#include "../objects/textures/Texture.h"

class TextureShaderProgram : public MaterialShaderProgram
{
public:
	TextureShaderProgram(GLuint shader_program, GLint uniform_transformation_location, GLint uniform_materialColor_location, GLint uniform_texture_unit_location);
	void SetTexture(Texture* texture);
private:
	GLint textureUnitLocation;
};