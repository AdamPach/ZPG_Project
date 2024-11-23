#include "InputController.h"
#include "requests/ChangeSceneRequest.h"
#include "requests/ExitRequest.h"
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
	}
}

void InputController::HandleMouseMoveInput(double xpos, double ypos)
{
}

void InputController::SetMediator(Mediator* mediator)
{
	this->mediator = mediator;
}
