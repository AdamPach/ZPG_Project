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
	Texture* GetTreeTexture();
	Texture* GetZombieTexture();
private:
	TexturesManager();
	static TexturesManager* instance;

	Texture* houseTexture = nullptr;
	Texture* grassTexture = nullptr;
	Texture* treeTexture = nullptr;
	Texture* zombieTexture = nullptr;
	TextureCubeMap* skycube = nullptr;
};