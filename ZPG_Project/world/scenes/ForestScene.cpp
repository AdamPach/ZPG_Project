#include "ForestScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../objects/PlainModel.h"
#include "../../objects/TreeModel.h"
#include "../../objects/BushesModel.h"
#include "../../objects/SphereObject.h"
#include "../../transformations/RandomDynamicMovement.h"
#include "../../transformations/TransformationsBuilder.h"

ForestScene::ForestScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler) : Scene(keyboardHander, mouseHandler)
{

}

void ForestScene::InitShaders()
{
	ShaderProgram::ShaderProgramBuilder builder;

	builder.AddVertexShader("vertext_position_color.vert")
		->AddFragmentShader("fragment_position_color.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	auto color_shader_program = builder.Build();

	AddShaderProgram(color_shader_program, "basic_shader");
}


void ForestScene::InitScene()
{
	auto color_shader_program = GetShaderProgram("basic_shader");

	TransformationsBuilder transformationBuilder;

	transformationBuilder.AddScale(20.0f)
		->AddTranslation(0, -0.5f, 0);

	AddObject(new SimpleDrawableObject(
		PlainModel::GetInstance(),
		color_shader_program,
		new Transformation(transformationBuilder.Build())));

	for (int i = 0; i < 10; i++)
	{
		auto base = transformationBuilder
			.AddRotation(20 * i, Axis::Y)
			->AddScale(i * 0.01f + 0.1f)
			->AddTranslation(0, -0.5f, 0)
			->Build();

		for (int j = 0; j < 10; j++)
		{
			transformationBuilder.AddTransformation(base)->AddTranslation(rand() % 38 - 19, 0, rand() % 38 - 19);
			AddObject(new SimpleDrawableObject(
				TreeModel::GetInstance(),
				color_shader_program,
				new Transformation(transformationBuilder.Build())));
		}
	}

	for (int i = 0; i < 10; i++)
	{
		auto base = transformationBuilder
			.AddRotation(20 * i, Axis::Y)
			->AddScale(i * 0.05f + 0.1f)
			->AddTranslation(0, -0.5f, 0)
			->Build();

		for (int j = 0; j < 10; j++)
		{
			transformationBuilder.AddTransformation(base)->AddTranslation(rand() % 38 - 19, 0, rand() % 38 - 19);
			AddObject(new SimpleDrawableObject(
				BushesModel::GetInstance(),
				color_shader_program,
				new Transformation(transformationBuilder.Build())));
		}
	}

	for (int i = 0; i < 100; i++)
	{
		auto base = transformationBuilder
			.AddTranslation(0, 1, -2)
			->AddTransformation(new RandomDynamcMovement())
			->AddScale(0.05f);

		AddObject(new SimpleDrawableObject(
			SphereObject::GetInstance(),
			color_shader_program,
			new Transformation(transformationBuilder.Build())
		));
	}
}