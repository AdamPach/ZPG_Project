#pragma once

#include <vector>
#include "requests/KeyActionRequest.h"
#include "InputMediator.h"

enum Keys {
	W = 0,
	A = 1,
	S = 2,
	D = 3
};

class KeyboardHandler : public RequestHandler<KeyActionRequest>
{
public:
	void HandleRequest(KeyActionRequest request) override;
	std::vector<Keys> GetPressedKeys();
private:
	void SetKey(int key);
	void ReleaseKey(int key);

	bool W_pressed = false;
	bool A_pressed = false;
	bool S_pressed = false;
	bool D_pressed = false;
};