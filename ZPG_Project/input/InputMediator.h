#pragma once

#include "../abstraction/Mediator.h"
#include "../abstraction/RequestHandler.h"

#include "requests/ExitRequest.h"
#include "requests/ChangeSceneRequest.h"
#include "requests/WindowSizeChangedRequest.h"
#include "requests/KeyActionRequest.h"
#include "requests/MouseMoveRequest.h"

class Application;
class Camera;
class KeyboardHandler;
class MouseHandler;

class InputMediator : public Mediator
{
public:
	InputMediator(Application* application, Camera* camera, KeyboardHandler* keyboard_handler, MouseHandler* mouseHandler);
	void Send(Request * request) override;
private:
	Application* application;
	Camera* camera;
	KeyboardHandler* keyboard_handler;
	MouseHandler* mouseHandler;
};