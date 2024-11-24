#include "TextureShaderProgram.h"

TextureShaderProgram::TextureShaderProgram(GLuint shader_program, GLint uniform_transformation_location, GLint uniform_materialColor_location, GLint uniform_texture_unit_location)
	: MaterialShaderProgram(shader_program, uniform_transformation_location, uniform_materialColor_location)
{
	textureUnitLocation = uniform_texture_unit_location;
}

void TextureShaderProgram::SetTexture(Texture* texture)
{
	Use();
	if (textureUnitLocation != -1)
	{
		glUniform1i(textureUnitLocation, texture->GetTextureUnit());
	}
	Unuse();
}