#include "Application.h"
#include "objects/TriangleNormalModel.h"
#include "transformations/TransformationsBuilder.h"
#include "objects/PlainModel.h"
#include "objects/TreeModel.h"
#include "objects/BushesModel.h"
#include "world/scenes/ForestScene.h"
#include "world/scenes/FourSpheresScene.h"
#include "defaults.h"

#include <stdio.h>
#include <cstdlib>

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

	if (action == GLFW_PRESS)
	{
		
		if (key == GLFW_KEY_1)
		{
			app->scene_index = app->scene_index <= 0 ? app->scenes.size() - 1 : app->scene_index - 1;
			return;
		}
		else if (key == GLFW_KEY_2)
		{
			app->scene_index = app->scene_index >= app->scenes.size() - 1 ? 0 : app->scene_index + 1;
			return;
		}
		else if (key == GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(window, GLFW_TRUE);
			return;
		}
	}

	app->keyboard_handler.HandleKeyboardInput(key, scancode, action, mods);
}

void Application::mouse_move_callback(GLFWwindow* window, double xpos, double ypos)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

	app->mouse_handler.HandleMouseMove(xpos, ypos);

}

void Application::Init()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	InitWindow();
	InitGLEW();
	PrintVersionInfo();

	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_move_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//scenes.push_back(new Scene(&keyboard_handler, &mouse_handler));
	//scenes.push_back(new Scene(&keyboard_handler, &mouse_handler));

	this->scene_index = 0;

	glEnable(GL_DEPTH_TEST);
}

void Application::AddScenes()
{
	scenes.push_back((new FourSpheresScene(&keyboard_handler, &mouse_handler))->Init());
	scenes.push_back((new ForestScene(&keyboard_handler, &mouse_handler))->Init());
}

void Application::Run()
{
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scenes[scene_index]->Draw();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);

	glfwTerminate();
}

void Application::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void Application::InitWindow()
{
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "ZPG", NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
}

void Application::InitGLEW()
{
	glewExperimental = GL_TRUE;
	glewInit();
}

void Application::PrintVersionInfo()
{
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}
