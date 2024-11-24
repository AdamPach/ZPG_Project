#include "WindowSizeChangedRequest.h"

WindowSizeChangedRequest::WindowSizeChangedRequest()
{
	this->width = 0;
	this->height = 0;
}

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
