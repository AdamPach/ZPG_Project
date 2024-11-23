#pragma once

#include "Scene.h"

class FourSpheresScene : public Scene
{
public:
	FourSpheresScene(MouseHandler* mouseHandler);
protected:
	void InitShaders() override;
	void InitScene() override;
};