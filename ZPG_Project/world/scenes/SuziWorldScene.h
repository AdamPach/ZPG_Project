#pragma once

#include "Scene.h"

class SuziWorldScene : public Scene
{
public:
	SuziWorldScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
protected:
	void InitShaders() override;
	void InitScene() override;
};