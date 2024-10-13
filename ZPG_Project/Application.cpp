#include "Application.h"
#include "TriangleNormalModel.h"
#include "sphere.h"
#include "RotationPart.h"
#include "ScalePart.h"

#include <stdio.h>
#include <cstdlib>

float points[] = {
   -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
   -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

float points_2[] = {
	0.8f, 0.8f, 0.0f,
	0.8f, 0.5f, 0.0f,
	0.5f, 0.8f, 0.0f,
	0.5f, 0.5f, 0.0f,
	0.8f, 0.5f, 0.0f,
	0.5f, 0.8f, 0.0f
};

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

	shader_program = new ShaderProgram();

	glEnable(GL_DEPTH_TEST);
}

void Application::AddObjects()
{
	std::vector<TransformationPart*> parts;

	parts.push_back(new RotationPart(50.0f, glm::vec3(0.0f, 1.0f, 0.0f)));
	parts.push_back(new ScalePart(glm::vec3(0.5f)));

	objects.push_back(new DrawableObject(
		new TriangleNormalModel(sphere, sizeof(sphere)),
		shader_program,
		new Transformation(shader_program->GetUniformLocation("modelMatrix"), parts)));
}

void Application::AddShaders()
{
	shader_program->AddShader(new VertexShader(vertex_shader_color));
	shader_program->AddShader(new FragmentShader(fragment_shader_color));

	shader_program->Compile();
	shader_program->Check();
}

void Application::Run()
{
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (DrawableObject* drawableObject : objects)
		{
			drawableObject->DrawObject();
		}

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
