#pragma once

#include "../../abstraction/Request.h"

class ChangeSceneRequest : public Request
{
public:
	enum ChangeDirection
	{
		CHANGE_RIGHT,
		CHANGE_LEFT
	};
	ChangeSceneRequest(ChangeDirection direction);
	ChangeDirection GetDirection();
private:
	ChangeDirection direction;
};