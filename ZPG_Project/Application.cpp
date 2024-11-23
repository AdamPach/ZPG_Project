#include "Application.h"
#include "objects/TriangleNormalModel.h"
#include "transformations/TransformationsBuilder.h"
#include "objects/PlainModel.h"
#include "objects/TreeModel.h"
#include "objects/BushesModel.h"
#include "world/scenes/DefaultScene.h"
#include "world/scenes/ForestScene.h"
#include "world/scenes/FourSpheresScene.h"
#include "world/scenes/SuziWorldScene.h"
#include "defaults.h"

#include <time.h>
#include <stdio.h>
#include <cstdlib>

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

	app->input_controller.HandleKeyboardInput(key, scancode, action, mods);
}

void Application::mouse_move_callback(GLFWwindow* window, double xpos, double ypos)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

	app->input_controller.HandleMouseMoveInput(xpos, ypos);
}

void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));

	app->input_controller.HandleWindowSizeChanged(width, height);
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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	srand(time(NULL));

	this->scene_index = 0;

	glEnable(GL_DEPTH_TEST);
}

void Application::AddScenes()
{
	scenes.push_back((new DefaultScene())->Init());
	scenes.push_back((new FourSpheresScene())->Init());
	scenes.push_back((new ForestScene())->Init());
	scenes.push_back((new SuziWorldScene())->Init());

	input_controller.SetMediator(scenes[scene_index]->GetInputMediator(this));
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

void Application::HandleRequest(ChangeSceneRequest request)
{
	if (request.GetDirection() == ChangeSceneRequest::CHANGE_LEFT)
	{
		scene_index = scene_index <= 0 ? scenes.size() - 1 : scene_index - 1;
	}
	else if (request.GetDirection() == ChangeSceneRequest::CHANGE_RIGHT)
	{
		scene_index = scene_index >= scenes.size() - 1 ? 0 : scene_index + 1;
	}

	input_controller.SetMediator(scenes[scene_index]->GetInputMediator(this));
}

void Application::HandleRequest(ExitRequest request)
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
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
