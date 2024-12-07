#include "MouseClickReactionRequest.h"

MouseClickedReactionRequest::MouseClickedReactionRequest(int x, int y)
{
	this->x = x;
	this->y = y;
}

int MouseClickedReactionRequest::GetX() const
{
	return x;
}

int MouseClickedReactionRequest::GetY() const
{
	return y;
}