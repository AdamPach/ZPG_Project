#pragma once

#include "SkyCubeScene.h"

class TexturedForestScene : public SkyCubeScene
{
public:
	TexturedForestScene();

	void HandleRequest(MouseClickedReactionRequest request) override;
protected:
	void InitScene() override;
	void InitShaders() override;
private:
	Material* defaultMaterial;
	Model* tree;
	Model* zombie;

	std::vector<glm::vec3> bezierPoints;
};