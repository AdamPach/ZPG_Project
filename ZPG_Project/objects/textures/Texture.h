#pragma once

class Texture
{
public:
	virtual ~Texture();

	int GetTextureUnit();
protected:
	Texture(int texture_unit);
private:
	int texture_unit;
};
