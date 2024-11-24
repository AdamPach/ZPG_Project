#include "TexturesManager.h"

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
		grassTexture = new Texture("grass.png", 0);
	}

	return grassTexture;
}

TexturesManager::TexturesManager()
{
}

TexturesManager* TexturesManager::instance = nullptr;
