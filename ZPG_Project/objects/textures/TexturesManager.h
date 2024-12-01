#pragma once

#include "TextureCubeMap.h"
#include "Texture.h"

class TexturesManager
{
public:
	static TexturesManager* GetInstance();

	Texture* GetGrassTexture();
	TextureCubeMap* GetSkycube();
	Texture* GetHouseTexture();
private:
	TexturesManager();
	static TexturesManager* instance;

	Texture* houseTexture = nullptr;
	Texture* grassTexture = nullptr;
	TextureCubeMap* skycube = nullptr;
};