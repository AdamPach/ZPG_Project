#include "MouseHandler.h"

void MouseHandler::HandleRequest(MouseMoveRequest request)
{
	int xpos = request.GetX();
	int ypos = request.GetY();

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	xoffset = xpos - lastX;
	yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;
}

float MouseHandler::GetXOffset()
{
	float offset = static_cast<float>(this->xoffset);

	this->xoffset = 0;
	
	return static_cast<float>(offset);
}

float MouseHandler::GetYOffset()
{
	float offset = static_cast<float>(this->yoffset);

	this->yoffset = 0;

	return static_cast<float>(offset);
}