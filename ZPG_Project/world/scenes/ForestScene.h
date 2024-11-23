#pragma once

#include "Scene.h"

class ForestScene : public Scene
{
public:
	ForestScene(MouseHandler* mouseHandler);
protected:
	void InitScene() override;
	void InitShaders() override;
};