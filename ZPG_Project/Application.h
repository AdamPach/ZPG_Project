#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Application
{
public:
	void Init();
	void AddObjects();
	void AddShaders();
	void Run();
private:
	GLFWwindow* window;
	GLuint VBO, VAO;
	GLuint shaderProgram;
	static void error_callback(int error, const char* description);
	void InitWindow();
	void InitGLEW();
	void PrintVersionInfo();
};
