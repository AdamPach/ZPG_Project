#include "Application.h"
#include "TriangleNormalModel.h"
#include "TransformationsCollectionBuilder.h"
#include "PlainModel.h"
#include "TreeModel.h"
#include "BushesModel.h"

#include <stdio.h>
#include <cstdlib>

const char* vertex_shader =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"void main () {"
"     gl_Position = vec4 (vp, 1.0);"
"}";

const char* vertex_shader_color =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 color_in;"
"uniform mat4 modelMatrix;"
"out vec3 color_out;"
"void main () {"
"     gl_Position = modelMatrix * vec4 (vp, 1.0);"
"     color_out = color_in;"
"}";

const char* fragment_shader =
"#version 330\n"
"out vec4 frag_colour;"
"void main () {"
"     frag_colour = vec4 (0.5, 0.5, 0.0, 1.0);"
"}";

const char* fragment_shader_color =
"#version 330\n"
"in vec3 color_out;"
"out vec4 frag_colour;"
"void main () {"
"     frag_colour = vec4 (color_out, 1.0);"
"}";

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
		if (key == GLFW_KEY_1)
		{
			app->scene_index = 0;
		}
		else if (key == GLFW_KEY_2)
		{
			app->scene_index = 1;
		}
	}
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

	scenes.push_back(new Scene());
	scenes.push_back(new Scene());

	this->scene_index = 0;

	glEnable(GL_DEPTH_TEST);
}

void Application::AddObjects()
{
	TransformationsCollectionBuilder transformationBuilder;

	transformationBuilder.AddTranslationPart(0,0,0.99)
		->AddRotationPart(90, TransformationsCollectionBuilder::X);

	scenes[0]->AddObject(new DrawableObject(
		PlainModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddRotationPart(30, TransformationsCollectionBuilder::Y)
		->AddScalePart(0.05f);

	auto baseTransformation = transformationBuilder.Build();
	auto baseRotated = transformationBuilder.AddPart(baseTransformation)
		->AddRotationPart(10, TransformationsCollectionBuilder::X)->Build();

	transformationBuilder.AddPart(baseTransformation)
		->AddTranslationPart(8, 0, 0);

	scenes[0]->AddObject(new DrawableObject(
		TreeModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddPart(baseRotated)
		->AddScalePart(1.5f)
		->AddTranslationPart(-6, 5, 0);

	scenes[0]->AddObject(new DrawableObject(
		TreeModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddPart(baseRotated)
		->AddScalePart(1.3f)
		->AddTranslationPart(-8, -5, 0);

	scenes[0]->AddObject(new DrawableObject(
		TreeModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddPart(baseTransformation)
		->AddScalePart(1.2f)
		->AddTranslationPart(4, -8, 0);

	scenes[0]->AddObject(new DrawableObject(
		TreeModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddPart(baseTransformation)
		->AddScalePart(4.0f)
		->AddTranslationPart(2, -4, 0);

	scenes[0]->AddObject(new DrawableObject(
		BushesModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddPart(baseTransformation)
		->AddScalePart(4.0f)
		->AddTranslationPart(-2, -4, 0)
		->AddRotationPart(60, TransformationsCollectionBuilder::X);

	scenes[0]->AddObject(new DrawableObject(
		BushesModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddPart(baseTransformation)
		->AddScalePart(4.0f)
		->AddTranslationPart(2, 4, 0)
		->AddRotationPart(40, TransformationsCollectionBuilder::X)
		->AddRotationPart(40, TransformationsCollectionBuilder::Z);

	scenes[0]->AddObject(new DrawableObject(
		BushesModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddScalePart(0.6f)
		->AddRotationPart(60, TransformationsCollectionBuilder::X)
		->AddRotationPart(60, TransformationsCollectionBuilder::Y)
		->AddRotationPart(60, TransformationsCollectionBuilder::Z);

	scenes[1]->AddObject(new DrawableObject(
		PlainModel::GetInstance(),
		shader_program,
		new Transformation(transformationBuilder.Build())));
		
}

void Application::AddShaders()
{
	ShaderProgram::ShaderProgramBuilder builder;

	builder.AddVertexShader(vertex_shader_color);
	builder.AddFragmentShader(fragment_shader_color);

	shader_program = builder.Build();

	scenes[0]->AddShaderProgram(shader_program);
	scenes[1]->AddShaderProgram(shader_program);
}

void Application::Run()
{
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scenes[scene_index]->Draw();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we�ve been drawing onto the display
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
	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);

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
