#pragma once

#include "Scene.h"
#include "../../objects/drawable/DrawableObject.h"
#include "../../objects/textures/TextureCubeMap.h"
#include "../../transformations/ObservableOffMovement.h"


class SkyCubeScene : public Scene
{
public:
	void Draw() override;
	virtual InputMediator* GetInputMediator(Application* application)override;
protected:
	SkyCubeScene(TextureCubeMap * skyCube_texture);
	static SkyCubeScene* instance;
private:
	DrawableObject* skyCube;
	ObservableOffMovement* observableOffMovement;
};