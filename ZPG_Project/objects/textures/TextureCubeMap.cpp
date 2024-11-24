#include "TextureCubeMap.h"
#include <iostream>
#include "../../defaults.h"
#include <SOIL.h>
#include <GL/glew.h>

TextureCubeMap::TextureCubeMap(int texture_unit, const char* posx, const char* posy, const char* posz, const char* negx, const char* negy, const char* negz)
	: Texture(texture_unit)
{
	std::string posX = std::string(TEXTURE_PATH).append(posx);
	std::string posY = std::string(TEXTURE_PATH).append(posy);
	std::string posZ = std::string(TEXTURE_PATH).append(posz);
	std::string negX = std::string(TEXTURE_PATH).append(negx);
	std::string negY = std::string(TEXTURE_PATH).append(negy);
	std::string negZ = std::string(TEXTURE_PATH).append(negz);

	GLuint textureId = SOIL_load_OGL_cubemap(posX.c_str(), negX.c_str(), posY.c_str(), negY.c_str(), posZ.c_str(), negZ.c_str(), SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	if (textureId == 0)
	{
		std::cout << "Error loading cubemap texture" << std::endl;
		exit(EXIT_FAILURE);
	}

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
}
