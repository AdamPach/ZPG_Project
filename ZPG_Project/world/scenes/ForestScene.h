#pragma once

#include "Scene.h"

class ForestScene : public Scene
{
public:
	ForestScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
	Scene* InitScene() override;
};