#pragma once

#include "../abstraction/RequestHandler.h"
#include "requests/MouseMoveRequest.h"
#include "requests/MouseClickedRequest.h"
#include "../abstraction/Mediator.h"

class MouseHandler : public RequestHandler<MouseMoveRequest>, public RequestHandler<MouseClickedRequest>
{
public:
	void HandleRequest(MouseMoveRequest request) override;
	void HandleRequest(MouseClickedRequest request) override;
	float GetXOffset();
	float GetYOffset();

	void SetMediator(Mediator* mediator);
private:
	double lastX = 0;
	double lastY = 0;
	double xoffset = 0;
	double yoffset = 0;
	bool firstMouse = true;
	Mediator* mediator = nullptr;
};