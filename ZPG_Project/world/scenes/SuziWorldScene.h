#pragma once

#include "Scene.h"

class SuziWorldScene : public Scene
{
public:
	SuziWorldScene(MouseHandler* mouseHandler);
protected:
	void InitShaders() override;
	void InitScene() override;
};