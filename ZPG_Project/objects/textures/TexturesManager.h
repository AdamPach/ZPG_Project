#pragma once

#include "Texture.h"

class TexturesManager
{
public:
	static TexturesManager* GetInstance();

	Texture* GetGrassTexture();
	Texture* GetSkycube();
private:
	TexturesManager();
	static TexturesManager* instance;

	Texture* grassTexture = nullptr;
	Texture* skycube = nullptr;
};