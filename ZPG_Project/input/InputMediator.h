#pragma once

#include "../abstraction/Mediator.h"
#include "../abstraction/RequestHandler.h"

#include "requests/ExitRequest.h"
#include "requests/ChangeSceneRequest.h"
#include "requests/WindowSizeChangedRequest.h"
#include "requests/KeyActionRequest.h"
#include "requests/MouseMoveRequest.h"

class Application;
class WindowSizeHandler;
class KeyboardHandler;
class MouseHandler;

class InputMediator : public Mediator
{
public:
	InputMediator(Application* application, KeyboardHandler* keyboard_handler, MouseHandler* mouseHandler);
	void Send(Request * request) override;
private:
	Application* application;
	WindowSizeHandler* window_size_handler;
	KeyboardHandler* keyboard_handler;
	MouseHandler* mouseHandler;
};