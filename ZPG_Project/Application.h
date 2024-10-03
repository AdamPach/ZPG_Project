#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Object.h"
#include "SimpleTriangleObject.h"

class Application
{
public:
	void Init();
	void AddObjects();
	void AddShaders();
	void Run();
private:
	GLFWwindow* window;
	Object* triangle;
	GLuint shaderProgram;
	static void error_callback(int error, const char* description);
	void InitWindow();
	void InitGLEW();
	void PrintVersionInfo();
};
