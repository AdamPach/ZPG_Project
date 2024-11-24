#pragma once

#include "Texture.h"

class TextureCubeMap : public Texture
{
public:
	TextureCubeMap(int texture_unit, const char * posx, const char* posy, const char* posz, const char * negx, const char* negy, const char* negz);
};