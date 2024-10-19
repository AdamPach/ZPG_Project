#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "objects/DrawableObject.h"
#include "shaders/VertexShader.h"
#include "shaders/FragmentShader.h"
#include "shaders/ShaderProgram.h"
#include "world/Scene.h"

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
	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void InitWindow();
	void InitGLEW();
	void PrintVersionInfo();
};
