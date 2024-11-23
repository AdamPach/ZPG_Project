#include "ChangeSceneRequest.h"

ChangeSceneRequest::ChangeSceneRequest(ChangeDirection direction)
{
	this->direction = direction;
}

ChangeSceneRequest::ChangeDirection ChangeSceneRequest::GetDirection()
{
	return direction;
}
