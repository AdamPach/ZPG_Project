#include "MouseClickedRequest.h"

MouseClickedRequest::MouseClickedRequest(int button, MouseAction action)
{
	this->button = button;
	this->action = action;

}

int MouseClickedRequest::GetButton() const
{
	return this->button;
}

MouseClickedRequest::MouseAction MouseClickedRequest::GetAction() const
{
	return this->action;
}