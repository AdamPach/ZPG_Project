#include "DefaultScene.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/TriangleNormalModel.h"

float triangleVertices[] = {
	-0.5f, -0.5f, 0.0f, 0.73f, 0.18f, 0.66f,
	0.5f, -0.5f, 0.0f, 0.73f, 0.18f, 0.66f,
	0.0f, 0.5f, 0.0f, 0.73f, 0.18f, 0.66f
};

DefaultScene::DefaultScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler) : Scene(keyboardHander, mouseHandler)
{
}

void DefaultScene::InitShaders()
{
	auto shaderBuilder = ShaderProgramBuilder();

	shaderBuilder.AddVertexShader("vertext_position_color.vert")
		->AddFragmentShader("fragment_position_color.vert")
		->AddTransformationUniform("modelMatrix");

	AddShaderProgram(shaderBuilder.Build(), "basic_shader");

	shaderBuilder.AddVertexShader("vertext_position_color.vert")
		->AddFragmentShader("fragment_position_color.vert")
		->AddTransformationUniform("modelMatrix");

	AddShaderProgram(shaderBuilder.Build(), "basic_shader_2");
}

void DefaultScene::InitScene()
{
	auto color_shader_program = GetShaderProgram("basic_shader");

	TransformationsBuilder transformationBuilder;

	TriangleNormalModel* triangleModel = new TriangleNormalModel(triangleVertices, sizeof(triangleVertices));

	AddObject(new SimpleDrawableObject(
		triangleModel,
		color_shader_program,
		new Transformation(transformationBuilder.Build())));

	auto color_shader_program_2 = GetShaderProgram("basic_shader_2");

	transformationBuilder.AddTranslation(1.0f, 0, 0);

	AddObject(new SimpleDrawableObject(
		triangleModel,
		color_shader_program_2,
		new Transformation(transformationBuilder.Build())));
}
