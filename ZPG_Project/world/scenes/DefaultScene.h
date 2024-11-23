#pragma once

#include "Scene.h"

class DefaultScene : public Scene
{
public:
	DefaultScene(MouseHandler* mouseHandler);
protected:
	void InitShaders() override;
	void InitScene() override;
};