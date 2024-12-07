#pragma once

#include "../../abstraction/Request.h"

class MouseClickedRequest : public Request 
{
public:
	enum MouseAction
	{
		MOUSE_PRESSED,
		MOUSE_RELEASED
	};

	MouseClickedRequest(int button, MouseAction action);

	int GetButton() const;
	MouseAction GetAction() const;
private:
	int button;
	MouseAction action;

};