#include "WindowSizeHandler.h"

void WindowSizeHandler::HandleRequest(WindowSizeChangedRequest request)
{
	width = request.GetWidth();
	height = request.GetHeight();

	value = static_cast<float>(width) / height;

	Notify();
}

float WindowSizeHandler::GetValue()
{
	return value;
}

int WindowSizeHandler::GetHeight() const
{
	return height;
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
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;

	value = static_cast<float>(width) / height;
}

WindowSizeHandler* WindowSizeHandler::instance = nullptr;