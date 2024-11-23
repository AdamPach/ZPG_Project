#pragma once

#include "../abstraction/RequestHandler.h"
#include "requests/MouseMoveRequest.h"

class MouseHandler : public RequestHandler<MouseMoveRequest>
{
public:
	void HandleRequest(MouseMoveRequest request) override;
	float GetXOffset();
	float GetYOffset();
private:
	double lastX = 0;
	double lastY = 0;
	double xoffset = 0;
	double yoffset = 0;
	bool firstMouse = true;
};