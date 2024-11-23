#pragma once

#include "../../abstraction/Request.h"

class KeyActionRequest : public Request
{
public:
	enum KeyAction
	{
		KEY_PRESSED,
		KEY_RELEASED
	};
	KeyActionRequest(int key, KeyAction action);
	int GetKey();
	KeyAction GetAction();
private:
	int key;
	KeyAction action;
};