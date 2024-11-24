#pragma once

#include "SkyCubeScene.h"

class SuziWorldScene : public SkyCubeScene
{
public:
	SuziWorldScene();
protected:
	void InitShaders() override;
	void InitScene() override;
};