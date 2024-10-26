#include "ForestScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../objects/PlainModel.h"
#include "../../objects/TreeModel.h"
#include "../../objects/BushesModel.h"
#include "../../transformations/TransformationsBuilder.h"

ForestScene::ForestScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler) : Scene(keyboardHander, mouseHandler)
{

}

Scene* ForestScene::InitScene()
{
	ShaderProgram::ShaderProgramBuilder builder;

	builder.AddVertexShader("vertext_position_color.vert")
		->AddFragmentShader("fragment_position_color.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	auto color_shader_program = builder.Build();

	AddShaderProgram(color_shader_program);

	TransformationsBuilder transformationBuilder;

	transformationBuilder.AddScale(20.0f)
		->AddTranslation(0, -0.5f, 0);

	AddObject(new DrawableObject(
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
			AddObject(new DrawableObject(
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
			AddObject(new DrawableObject(
				BushesModel::GetInstance(),
				color_shader_program,
				new Transformation(transformationBuilder.Build())));
		}
	}

	return this;
}
