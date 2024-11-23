#pragma once

#include "../../abstraction/Request.h"

class WindowSizeChangedRequest : public Request
{
public:
	WindowSizeChangedRequest(int width, int height);
	int GetWidth();
	int GetHeight();
private:
	int width;
	int height;
};