#include "KeyActionRequest.h"

KeyActionRequest::KeyActionRequest(int key, KeyAction action)
{
	this->key = key;
	this->action = action;
}

int KeyActionRequest::GetKey()
{
	return key;
}

KeyActionRequest::KeyAction KeyActionRequest::GetAction()
{
	return action;
}
