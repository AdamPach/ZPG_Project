#pragma once

#include "Texture.h"

class TexturesManager
{
public:
	static TexturesManager* GetInstance();

	Texture* GetGrassTexture();
private:
	TexturesManager();
	static TexturesManager* instance;

	Texture* grassTexture = nullptr;
};