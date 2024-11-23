#pragma once

#include "../abstraction/Mediator.h"
#include "../abstraction/RequestHandler.h"

#include "requests/ExitRequest.h"
#include "requests/ChangeSceneRequest.h"

class InputMediator : public Mediator
{
public:
	InputMediator(RequestHandler<ChangeSceneRequest>* change_scene_handler, RequestHandler<ExitRequest>* exit_handler);
	void Send(Request * request) override;
private:
	RequestHandler<ChangeSceneRequest>* change_scene_handler;
	RequestHandler<ExitRequest>* exit_handler;
};