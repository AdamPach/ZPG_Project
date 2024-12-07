#include "MouseHandler.h"
#include <iostream>
#include <GL/glew.h>
#include "../defaults.h"
#include "WindowSizeHandler.h"

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

void MouseHandler::HandleRequest(MouseClickedRequest request)
{
	if (request.GetAction() == MouseClickedRequest::MOUSE_PRESSED)
	{
		GLfloat d;

		int newy = WindowSizeHandler::GetInstance()->GetHeight() - lastY;

		glReadPixels(lastX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &d);
		std::cout << "Depth: " << d << std::endl;
	}
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