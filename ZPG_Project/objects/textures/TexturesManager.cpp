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
		grassTexture = new Texture2D(0, "grass.png");
	}

	return grassTexture;
}

TexturesManager::TexturesManager()
{
}

TexturesManager* TexturesManager::instance = nullptr;
