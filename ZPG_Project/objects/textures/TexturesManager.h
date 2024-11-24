#pragma once

#include "TextureCubeMap.h"
#include "Texture.h"

class TexturesManager
{
public:
	static TexturesManager* GetInstance();

	Texture* GetGrassTexture();
	TextureCubeMap* GetSkycube();
private:
	TexturesManager();
	static TexturesManager* instance;

	Texture* grassTexture = nullptr;
	TextureCubeMap* skycube = nullptr;
};