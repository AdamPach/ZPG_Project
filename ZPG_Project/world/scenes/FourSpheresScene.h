#pragma once

#include "Scene.h"

class FourSpheresScene : public Scene
{
public:
	FourSpheresScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler);
protected:
	void InitShaders() override;
	void InitScene() override;
};