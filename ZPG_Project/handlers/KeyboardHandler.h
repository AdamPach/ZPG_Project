#pragma once

#include <GLFW/glfw3.h>
#include <vector>

enum Keys {
	W = 0,
	A = 1,
	S = 2,
	D = 3
};

class KeyboardHandler
{
public:
	void HandleKeyboardInput(int key, int scancode, int action, int mods);
	std::vector<Keys> GetPressedKeys();
private:
	void SetKey(int key);
	void ReleaseKey(int key);

	bool W_pressed = false;
	bool A_pressed = false;
	bool S_pressed = false;
	bool D_pressed = false;
};