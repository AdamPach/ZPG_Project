#include "InputMediator.h"
#include "../Application.h"

InputMediator::InputMediator(Application* application, Camera* camera, KeyboardHandler* keyboard_handler, MouseHandler* mouseHandler)
{
	this->application = application;
	this->camera = camera;
	this->keyboard_handler = keyboard_handler;
	this->mouseHandler = mouseHandler;
}

void InputMediator::Send(Request * request)
{
	auto change_scene_request = dynamic_cast<ChangeSceneRequest*>(request);

	if (change_scene_request != nullptr)
	{
		application->HandleRequest(*change_scene_request);
	}

	auto exit_request = dynamic_cast<ExitRequest*>(request);

	if (exit_request != nullptr)
	{
		application->HandleRequest(*exit_request);
	}

	auto window_size_changed_request = dynamic_cast<WindowSizeChangedRequest*>(request);

	if (window_size_changed_request != nullptr)
	{
		camera->HandleRequest(*window_size_changed_request);
	}

	auto key_action_request = dynamic_cast<KeyActionRequest*>(request);

	if (key_action_request != nullptr)
	{
		keyboard_handler->HandleRequest(*key_action_request);
	}

	auto mouse_move_request = dynamic_cast<MouseMoveRequest*>(request);

	if (mouse_move_request != nullptr)
	{
		mouseHandler->HandleRequest(*mouse_move_request);
	}


	delete request;
}
