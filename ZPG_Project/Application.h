#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "objects/DrawableObject.h"
#include "shaders/VertexShader.h"
#include "shaders/FragmentShader.h"
#include "shaders/ShaderProgram.h"
#include "world/Scene.h"
#include "handlers/KeyboardHandler.h"
#include "handlers/MouseHandler.h"

class Application
{
public:
	void Init();
	void AddObjects();
	void AddShaders();
	void Run();
private:
	GLFWwindow* window;
	int scene_index;
	std::vector<Scene*> scenes;
	ShaderProgram* shader_program;
	KeyboardHandler keyboard_handler;
	MouseHandler mouse_handler;

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_move_callback(GLFWwindow* window, double xpos, double ypos);

	void InitWindow();
	void InitGLEW();
	void PrintVersionInfo();
};
