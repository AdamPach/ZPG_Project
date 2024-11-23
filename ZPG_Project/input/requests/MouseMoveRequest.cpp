#include "MouseMoveRequest.h"

MouseMoveRequest::MouseMoveRequest(int x, int y)
{
	this->x = x;
	this->y = y;
}

int MouseMoveRequest::GetX()
{
	return x;
}

int MouseMoveRequest::GetY()
{
	return y;
}
