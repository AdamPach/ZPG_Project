#pragma once

#include "Scene.h"

class ForestScene : public Scene
{
public:
	ForestScene();

	void HandleRequest(MouseClickedReactionRequest request) override;
protected:
	void InitScene() override;
	void InitShaders() override;
};