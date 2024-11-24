#pragma once

#include "abstraction/Model.h"

class EmptyModel : public Model
{
public:
	void DrawModel() override;
	glm::vec3 GetModelCenter() override;
	static EmptyModel* GetInstance();
private:
	EmptyModel();
	static EmptyModel* instance;
};