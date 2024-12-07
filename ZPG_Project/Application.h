#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "shaders/ShaderProgram.h"
#include "world/scenes/Scene.h"
#include "abstraction/RequestHandler.h"
#include "input/requests/ChangeSceneRequest.h"
#include "input/requests/SwitchCursorLockStateRequest.h"
#include "input/requests/ExitRequest.h"
#include "input/InputController.h"

class Application : 
	RequestHandler<ChangeSceneRequest>,
	RequestHandler<ExitRequest>,
	RequestHandler<SwitchCursorLockStateRequest>
{
public:
	void Init();
	void AddScenes();
	void Run();
	void HandleRequest(ChangeSceneRequest request) override;
	void HandleRequest(ExitRequest request) override;
	void HandleRequest(SwitchCursorLockStateRequest request) override;
private:
	GLFWwindow* window;
	int scene_index;
	std::vector<Scene*> scenes;
	InputController input_controller;
	bool cursor_locked = false;

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_move_callback(GLFWwindow* window, double xpos, double ypos);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	void InitWindow();
	void InitGLEW();
	void PrintVersionInfo();
};
