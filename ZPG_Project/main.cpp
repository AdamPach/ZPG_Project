//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include "Application.h"


int main(void)
{
	Application* app = new Application();

	app->Init();

	app->AddObjects();

	app->AddShaders();

	app->Run();

	exit(EXIT_SUCCESS);

	delete app;
}