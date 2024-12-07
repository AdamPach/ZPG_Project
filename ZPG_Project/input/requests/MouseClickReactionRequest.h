#pragma once

#include "../../abstraction/Request.h"

class MouseClickedReactionRequest : public Request
{
public:
	MouseClickedReactionRequest(int x, int y);

	int GetX() const;
	int GetY() const;
private:
	int x, y;
};