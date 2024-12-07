#include "MouseClickReactionRequest.h"

MouseClickedReactionRequest::MouseClickedReactionRequest(int x, int y, MouseButton button)
{
	this->x = x;
	this->y = y;
	this->button = button;
}

int MouseClickedReactionRequest::GetX() const
{
	return x;
}

int MouseClickedReactionRequest::GetY() const
{
	return y;
}

MouseClickedReactionRequest::MouseButton MouseClickedReactionRequest::GetButton() const
{
	return button;
}

