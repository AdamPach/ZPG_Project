#pragma once

class Texture
{
public:
	Texture(const char* texture_name, int texture_unit);

	int GetTextureUnit();
private:
	int texture_unit;
};
