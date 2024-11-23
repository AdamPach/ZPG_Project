#include "InputMediator.h"

InputMediator::InputMediator(RequestHandler<ChangeSceneRequest>* change_scene_handler, RequestHandler<ExitRequest>* exit_handler, Camera* camera, RequestHandler<KeyActionRequest>* keyboard_handler)
{
	this->change_scene_handler = change_scene_handler;
	this->exit_handler = exit_handler;
	this->camera = camera;
	this->keyboard_handler = keyboard_handler;
}

void InputMediator::Send(Request * request)
{
	auto change_scene_request = dynamic_cast<ChangeSceneRequest*>(request);

	if (change_scene_request != nullptr)
	{
		change_scene_handler->HandleRequest(*change_scene_request);
	}

	auto exit_request = dynamic_cast<ExitRequest*>(request);

	if (exit_request != nullptr)
	{
		exit_handler->HandleRequest(*exit_request);
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

	delete request;
}
