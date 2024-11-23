#include "WindowSizeChangedRequest.h"

WindowSizeChangedRequest::WindowSizeChangedRequest(int width, int height)
{
	this->width = width;
	this->height = height;
}

int WindowSizeChangedRequest::GetWidth()
{
	return width;
}

int WindowSizeChangedRequest::GetHeight()
{
	return height;
}
