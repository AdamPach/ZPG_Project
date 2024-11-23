#include "InputMediator.h"

InputMediator::InputMediator(RequestHandler<ChangeSceneRequest>* change_scene_handler, RequestHandler<ExitRequest>* exit_handler)
{
	this->change_scene_handler = change_scene_handler;
	this->exit_handler = exit_handler;

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

	delete request;
}
