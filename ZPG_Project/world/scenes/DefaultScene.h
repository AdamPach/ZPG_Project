#pragma once

#include "Scene.h"

class DefaultScene : public Scene
{
public:
	DefaultScene();
protected:
	void InitShaders() override;
	void InitScene() override;
};