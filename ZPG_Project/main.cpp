#include "Application.h"

int main(void)
{
	Application* app = new Application();

	app->Init();

	app->AddScenes();

	app->Run();

	exit(EXIT_SUCCESS);

	delete app;
}