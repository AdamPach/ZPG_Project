#pragma once

#include "Scene.h"

class FourSpheresScene : public Scene
{
public:
	FourSpheresScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
	Scene* InitScene() override;
};