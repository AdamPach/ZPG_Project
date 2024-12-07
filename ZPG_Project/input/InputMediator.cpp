#include "InputMediator.h"
#include "../Application.h"
#include "WindowSizeHandler.h"


InputMediator::InputMediator(Application* application, KeyboardHandler* keyboard_handler, MouseHandler* mouseHandler)
{
	this->application = application;
	this->keyboard_handler = keyboard_handler;
	this->mouseHandler = mouseHandler;
	this->window_size_handler = WindowSizeHandler::GetInstance();
}

void InputMediator::SetSwitchObservingHandler(RequestHandler<SwitchObservingRequest>* handler)
{
	switchObservingHandler = handler;
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
		window_size_handler->HandleRequest(*window_size_changed_request);
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

	auto switch_observing_request = dynamic_cast<SwitchObservingRequest*>(request);

	if (switch_observing_request != nullptr && switchObservingHandler != nullptr)
	{
		switchObservingHandler->HandleRequest(*switch_observing_request);
	}

	auto switch_cursor_lock_state_request = dynamic_cast<SwitchCursorLockStateRequest*>(request);

	if (switch_cursor_lock_state_request != nullptr)
	{
		application->HandleRequest(*switch_cursor_lock_state_request);
	}

	auto mouse_clicked_request = dynamic_cast<MouseClickedRequest*>(request);

	if (mouse_clicked_request != nullptr)
	{
		mouseHandler->HandleRequest(*mouse_clicked_request);
	}

	delete request;
}
