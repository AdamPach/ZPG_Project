#pragma once

#include "../../abstraction/Request.h"

class MouseMoveRequest : public Request
{
public:
	MouseMoveRequest(int x, int y);
	int GetX();
	int GetY();
private:
	int x;
	int y;
};