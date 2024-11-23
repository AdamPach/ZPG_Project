#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "objects/drawable/DrawableObject.h"
#include "shaders/ShaderProgram.h"
#include "world/scenes/Scene.h"
#include "input/KeyboardHandler.h"
#include "input/MouseHandler.h"
#include "abstraction/RequestHandler.h"
#include "input/requests/ChangeSceneRequest.h"
#include "input/requests/ExitRequest.h"
#include "input/InputController.h"

class Application : RequestHandler<ChangeSceneRequest>, RequestHandler<ExitRequest>
{
public:
	void Init();
	void AddScenes();
	void Run();
	void HandleRequest(ChangeSceneRequest request) override;
	void HandleRequest(ExitRequest request) override;
private:
	GLFWwindow* window;
	int scene_index;
	std::vector<Scene*> scenes;
	ShaderProgram* shader_program;
	KeyboardHandler keyboard_handler;
	MouseHandler mouse_handler;
	InputController input_controller;

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_move_callback(GLFWwindow* window, double xpos, double ypos);

	void InitWindow();
	void InitGLEW();
	void PrintVersionInfo();
};
