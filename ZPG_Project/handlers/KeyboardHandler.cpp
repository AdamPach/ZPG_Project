#include "KeyboardHandler.h"

void KeyboardHandler::HandleKeyboardInput(int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		SetKey(key);
	}
	else if (action == GLFW_RELEASE)
	{
		ReleaseKey(key);
	}
}

std::vector<Keys> KeyboardHandler::GetPressedKeys()
{
	std::vector<Keys> pressedKeys;

	if (W_pressed)
	{
		pressedKeys.push_back(W);
	}
	if (A_pressed)
	{
		pressedKeys.push_back(A);
	}
	if (S_pressed)
	{
		pressedKeys.push_back(S);
	}
	if (D_pressed)
	{
		pressedKeys.push_back(D);
	}

	return pressedKeys;
}

void KeyboardHandler::SetKey(int key)
{
	if (key == GLFW_KEY_W)
	{
		W_pressed = true;
	}
	else if (key == GLFW_KEY_A)
	{
		A_pressed = true;
	}
	else if (key == GLFW_KEY_S)
	{
		S_pressed = true;
	}
	else if (key == GLFW_KEY_D)
	{
		D_pressed = true;
	}
}

void KeyboardHandler::ReleaseKey(int key)
{
	if (key == GLFW_KEY_W)
	{
		W_pressed = false;
	}
	else if (key == GLFW_KEY_A)
	{
		A_pressed = false;
	}
	else if (key == GLFW_KEY_S)
	{
		S_pressed = false;
	}
	else if (key == GLFW_KEY_D)
	{
		D_pressed = false;
	}
}
