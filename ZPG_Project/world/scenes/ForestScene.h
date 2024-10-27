#pragma once

#include "Scene.h"

class ForestScene : public Scene
{
public:
	ForestScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
protected:
	void InitScene() override;
	void InitShaders() override;
};