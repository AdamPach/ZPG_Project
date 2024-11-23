#pragma once

#include "../abstraction/Mediator.h"

class InputController
{
public:
	void HandleKeyboardInput(int key, int scancode, int action, int mods);
	void HandleMouseMoveInput(double xpos, double ypos);
	void HandleWindowSizeChanged(int width, int height);

	void SetMediator(Mediator* mediator);
private:
	Mediator* mediator = nullptr;
};