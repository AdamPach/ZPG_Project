#include "Texture2D.h"
#include <iostream>
#include "../../defaults.h"
#include <SOIL.h>
#include <GL/glew.h>


Texture2D::Texture2D(int texture_unit, const char* texture_name) : Texture(texture_unit)
{
	std::string texturePath = TEXTURE_PATH;
	texturePath.append(texture_name);

	GLuint textureId = SOIL_load_OGL_texture(texturePath.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

	if (textureId == 0)
	{
		std::cout << "Error loading texture: " << texture_name << std::endl;
		exit(EXIT_FAILURE);
	}

	glBindTexture(GL_TEXTURE_2D, textureId);
}