#include "SuziWorldScene.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/SuziFlatModel.h"
#include "../../objects/SuziSmoothModel.h"
#include "../../objects/DrawableObject.h"

SuziWorldScene::SuziWorldScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler) : Scene(keyboardHander, mouseHandler	)
{
}

void SuziWorldScene::InitShaders()
{
	auto shaderBuilder = ShaderProgram::ShaderProgramBuilder();

	shaderBuilder.AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_phong.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	AddShaderProgram(shaderBuilder.Build(), "phong_shader");

	shaderBuilder.AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_lambert.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	AddShaderProgram(shaderBuilder.Build(), "lambert_shader");

	shaderBuilder.AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_blinn.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	AddShaderProgram(shaderBuilder.Build(), "blinn_shader");

	shaderBuilder.AddVertexShader("vertex_position_normal_constant.vert")
		->AddFragmentShader("fragment_position_normal_constant.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	AddShaderProgram(shaderBuilder.Build(), "constant_shader");
}

void SuziWorldScene::InitScene()
{
	auto phongShaderProgram = GetShaderProgram("phong_shader");
	auto lambertShaderProgram = GetShaderProgram("lambert_shader");
	auto blinnShaderProgram = GetShaderProgram("blinn_shader");
	auto constantShaderProgram = GetShaderProgram("constant_shader");

	UseLight(Both);
	SetLigthPosition(0, 5, -7.5f);
	SetLightColor(1, 1, 1);

	UseCameraPosition();

	TransformationsBuilder transformationBuilder;

	auto smoothTransformation = transformationBuilder.AddRotation(90.0f, Axis::Y)
		->AddTranslation(-2.0f, 0, 0)
		->Build();

	auto baseMovement = transformationBuilder.AddTranslation(0, 0, -3.0f)->Build();

	transformationBuilder
		.AddTransformation(smoothTransformation)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziFlatModel::GetInstance(),
		phongShaderProgram,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder
		.AddTransformation(smoothTransformation)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziFlatModel::GetInstance(),
		lambertShaderProgram,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder
		.AddTransformation(smoothTransformation)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziFlatModel::GetInstance(),
		constantShaderProgram,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder
		.AddTransformation(smoothTransformation)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziFlatModel::GetInstance(),
		blinnShaderProgram,
		new Transformation(transformationBuilder.Build())));

	auto flatTransformation = transformationBuilder.AddRotation(-90.0f, Axis::Y)
		->AddTranslation(2.0f, 0, 0)
		->Build();

	transformationBuilder
		.AddTransformation(flatTransformation)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziSmoothModel::GetInstance(),
		phongShaderProgram,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder
		.AddTransformation(flatTransformation)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziSmoothModel::GetInstance(),
		lambertShaderProgram,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder
		.AddTransformation(flatTransformation)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziSmoothModel::GetInstance(),
		constantShaderProgram,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder
		.AddTransformation(flatTransformation)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement)
		->AddTransformation(baseMovement);

	AddObject(new DrawableObject(
		SuziSmoothModel::GetInstance(),
		blinnShaderProgram,
		new Transformation(transformationBuilder.Build())));
}
