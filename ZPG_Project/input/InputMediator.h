#pragma once

#include "../abstraction/Mediator.h"
#include "../abstraction/RequestHandler.h"
#include "../world/cameras/Camera.h"

#include "requests/ExitRequest.h"
#include "requests/ChangeSceneRequest.h"
#include "requests/WindowSizeChangedRequest.h"
#include "requests/KeyActionRequest.h"

class InputMediator : public Mediator
{
public:
	InputMediator(RequestHandler<ChangeSceneRequest>* change_scene_handler, RequestHandler<ExitRequest>* exit_handler, Camera* camera, RequestHandler<KeyActionRequest>* keyboard_handler);
	void Send(Request * request) override;
private:
	RequestHandler<ChangeSceneRequest>* change_scene_handler;
	RequestHandler<ExitRequest>* exit_handler;
	Camera* camera;
	RequestHandler<KeyActionRequest>* keyboard_handler;
};