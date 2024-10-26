#include "Application.h"

#include <direct.h>
#include <iostream>

#define GetCurrentDir _getcwd

int main(void)
{

	char buffer[FILENAME_MAX];
	if (GetCurrentDir(buffer, FILENAME_MAX))
	{
		std::string currentDir(buffer);
		std::cout << "Current working directory: " << currentDir << std::endl;
	}
	else
	{
		std::cerr << "Error getting current working directory" << std::endl;
	}

	Application* app = new Application();

	app->Init();

	app->AddShaders();

	app->AddObjects();

	app->AddScenes();

	app->Run();

	exit(EXIT_SUCCESS);

	delete app;
}