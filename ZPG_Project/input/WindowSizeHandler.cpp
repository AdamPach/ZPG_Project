#include "WindowSizeHandler.h"

void WindowSizeHandler::HandleRequest(WindowSizeChangedRequest request)
{
	value = static_cast<float>(request.GetWidth()) / request.GetHeight();
	Notify();
}

float WindowSizeHandler::GetValue()
{
	return value;
}

WindowSizeHandler* WindowSizeHandler::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new WindowSizeHandler();
	}

	return instance;
}

WindowSizeHandler::WindowSizeHandler()
{
	value = WINDOW_WIDTH / WINDOW_HEIGHT;
}

WindowSizeHandler* WindowSizeHandler::instance = nullptr;