#pragma once

#include "Scene.h"
#include "../../objects/drawable/DrawableObject.h"
#include "../../objects/textures/TextureCubeMap.h"

class SkyCubeScene : public Scene
{
public:
	void Draw() override;
protected:
	SkyCubeScene(TextureCubeMap * skyCube_texture);
	static SkyCubeScene* instance;
private:
	DrawableObject* skyCube;
};