#pragma once

#include "Scene.h"

class ForestScene : public Scene
{
public:
	ForestScene();
protected:
	void InitScene() override;
	void InitShaders() override;
};