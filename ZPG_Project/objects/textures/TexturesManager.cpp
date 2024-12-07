#include "TexturesManager.h"
#include "Texture2D.h"

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

TextureCubeMap* TexturesManager::GetSkycube()
{
	if (skycube == nullptr)
	{
		skycube = new TextureCubeMap(0, "posx.jpg", "posy.jpg", "posz.jpg", "negx.jpg", "negy.jpg", "negz.jpg");
	}

	return skycube;
}

Texture* TexturesManager::GetHouseTexture()
{
	if (houseTexture == nullptr)
	{
		houseTexture = new Texture2D(2, "house.png");
	}

	return houseTexture;
}

Texture* TexturesManager::GetTreeTexture()
{
	if (treeTexture == nullptr)
	{
		treeTexture = new Texture2D(3, "tree.png");
	}

	return treeTexture;
}

Texture* TexturesManager::GetZombieTexture()
{
	if (zombieTexture == nullptr)
	{
		zombieTexture = new Texture2D(4, "zombie.png");
	}

	return zombieTexture;
}

TexturesManager::TexturesManager()
{
}

TexturesManager* TexturesManager::instance = nullptr;
