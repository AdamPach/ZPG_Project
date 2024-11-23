#pragma once

#include "Scene.h"

class SuziWorldScene : public Scene
{
public:
	SuziWorldScene();
protected:
	void InitShaders() override;
	void InitScene() override;
};