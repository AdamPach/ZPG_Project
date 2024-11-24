#pragma once

#include "Texture.h"

class Texture2D : public Texture
{
public:
	Texture2D(int texture_unit, const char* texture_name);
};