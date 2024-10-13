#include "Application.h"


int main(void)
{
	Application* app = new Application();

	app->Init();

	app->AddShaders();

	app->AddObjects();

	app->Run();

	exit(EXIT_SUCCESS);

	delete app;
}