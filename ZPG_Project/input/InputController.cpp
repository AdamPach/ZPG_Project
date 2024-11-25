#include "InputController.h"
#include "requests/ChangeSceneRequest.h"
#include "requests/ExitRequest.h"
#include "requests/WindowSizeChangedRequest.h"
#include "requests/KeyActionRequest.h"
#include "requests/MouseMoveRequest.h"
#include "requests/SwitchObservingRequest.h"


#include <GLFW/glfw3.h>

void InputController::HandleKeyboardInput(int key, int scancode, int action, int mods)
{
	if (mediator == nullptr)
	{
		return;
	}

	if (action == GLFW_PRESS)
	{

		if (key == GLFW_KEY_1)
		{
			mediator->Send(new ChangeSceneRequest(ChangeSceneRequest::CHANGE_LEFT));
			return;
		}
		else if (key == GLFW_KEY_2)
		{
			mediator->Send(new ChangeSceneRequest(ChangeSceneRequest::CHANGE_RIGHT));
			return;
		}
		else if (key == GLFW_KEY_ESCAPE)
		{
			mediator->Send(new ExitRequest());
			return;
		}
		else if (key == GLFW_KEY_O)
		{
			mediator->Send(new SwitchObservingRequest());
			return;
		}
	}

	if (action == GLFW_PRESS)
	{
		mediator->Send(new KeyActionRequest(key, KeyActionRequest::KEY_PRESSED));
	}
	else if (action == GLFW_RELEASE)
	{
		mediator->Send(new KeyActionRequest(key, KeyActionRequest::KEY_RELEASED));
	}
	
}

void InputController::HandleMouseMoveInput(double xpos, double ypos)
{
	if (mediator == nullptr)
	{
		return;
	}

	mediator->Send(new MouseMoveRequest(xpos, ypos));
}

void InputController::HandleWindowSizeChanged(int width, int height)
{
	glViewport(0, 0, width, height);

	if (mediator == nullptr)
	{
		return;
	}

	mediator->Send(new WindowSizeChangedRequest(width, height));
}

void InputController::SetMediator(Mediator* mediator)
{
	this->mediator = mediator;
}
