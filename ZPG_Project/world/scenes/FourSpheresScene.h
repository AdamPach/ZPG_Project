#pragma once

#include "Scene.h"

class FourSpheresScene : public Scene
{
public:
	FourSpheresScene();
protected:
	void InitShaders() override;
	void InitScene() override;
};