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