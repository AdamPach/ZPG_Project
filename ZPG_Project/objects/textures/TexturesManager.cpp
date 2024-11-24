#include "TexturesManager.h"
#include "Texture2D.h"
#include "TextureCubeMap.h"

TexturesManager* TexturesManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new TexturesManager();
	}

    return instance;
}

Texture* TexturesManager::GetGrassTexture()
{
	if (grassTexture == nullptr)
	{
		grassTexture = new Texture2D(1, "grass.png");
	}

	return grassTexture;
}

Texture* TexturesManager::GetSkycube()
{
	if (skycube == nullptr)
	{
		skycube = new TextureCubeMap(0, "posx.jpg", "posy.jpg", "posz.jpg", "negx.jpg", "negy.jpg", "negz.jpg");
	}

	return skycube;
}

TexturesManager::TexturesManager()
{
}

TexturesManager* TexturesManager::instance = nullptr;
