#pragma once

#include "../../abstraction/Request.h"

class MouseClickedReactionRequest : public Request
{
public:
	enum MouseButton
	{
		LEFT,
		RIGHT,
		MIDDLE
	};


	MouseClickedReactionRequest(int x, int y, MouseButton button);

	int GetX() const;
	int GetY() const;
	MouseButton GetButton() const;
private:
	int x, y;
	MouseButton button;
};