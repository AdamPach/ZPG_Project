#include "ForestScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../objects/PlainModel.h"
#include "../../objects/TreeModel.h"
#include "../../objects/BushesModel.h"
#include "../../objects/SphereObject.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/drawable/MaterialDrawableObjectDecorator.h"
#include "../../objects/drawable/LightDrawableObjectDecorator.h"
#include "../../transformations/ObservableMovement.h"
#include "../../objects/EmptyModel.h"


ForestScene::ForestScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler) : Scene(keyboardHander, mouseHandler)
{

}

void ForestScene::InitShaders()
{
	ShaderProgramBuilder builder;

	builder.AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_attenuation_phong.vert")
		->AddTransformationUniform("modelMatrix")
		->AddMaterialUniform(DEFAULT_MATERIAL_COLOR_NAME);

	auto color_shader_program = builder.Build();

	AddShaderProgram(color_shader_program, "basic_shader");
}


void ForestScene::InitScene()
{
	auto color_shader_program = GetShaderProgram("basic_shader");

	UseCameraPosition();

	TransformationsBuilder transformationBuilder;

	transformationBuilder.AddScale(20.0f)
		->AddTranslation(0, -0.5f, 0);

	AddObject(new MaterialDrawableObjectDecorator( 
		new SimpleDrawableObject(
			PlainModel::GetInstance(),
			color_shader_program,
			new Transformation(transformationBuilder.Build())),
		new Material(glm::vec3(0.5f))));

	auto treeMaterial = new Material(glm::vec3(0, 0.5, 0));
	auto bushMaterial = new Material(glm::vec3(0.5, 0.25, 0.05));

	for (int i = 0; i < 10; i++)
	{
		auto base = transformationBuilder
			.AddRotation(20 * i, Axis::Y)
			->AddScale(i * 0.01f + 0.1f)
			->AddTranslation(0, -0.5f, 0)
			->Build();

		for (int j = 0; j < 10; j++)
		{
			transformationBuilder.AddTransformation(base)->AddTranslation(rand() % 18 - 9, 0, rand() % 18 - 9);
			AddObject(new MaterialDrawableObjectDecorator(
				new SimpleDrawableObject(
					TreeModel::GetInstance(),
					color_shader_program,
					new Transformation(transformationBuilder.Build())),
				treeMaterial));
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
			transformationBuilder.AddTransformation(base)->AddTranslation(rand() % 18 - 9, 0, rand() % 18 - 9);
			AddObject(new MaterialDrawableObjectDecorator(
				new SimpleDrawableObject(
					BushesModel::GetInstance(),
					color_shader_program,
					new Transformation(transformationBuilder.Build())),
				bushMaterial));
		}
	}

	/*
	for (int i = 0; i < 50; i++)
	{
		auto base = transformationBuilder.AddRandomDynamicMovvement()
			->AddScale(0.025f)
			->AddTranslation(rand() % 18 - 9, 1, rand() % 18 - 9);

		AddObject(new LightDrawableObjectDecorator(
			new MaterialDrawableObjectDecorator(
				new SimpleDrawableObject(
					SphereObject::GetInstance(),
					color_shader_program,
					new Transformation(transformationBuilder.Build())),
				new Material(glm::vec3(0.5, 0.5, 0))),
			new Light(glm::vec3(1,1,1))));
	}
	*/

	transformationBuilder.AddTransformation(new ObservableMovement(GetCameraPositionSubject()));

	AddObject(new LightDrawableObjectDecorator(
		new MaterialDrawableObjectDecorator(
			new SimpleDrawableObject(
				EmptyModel::GetInstance(),
				color_shader_program,
				new Transformation(transformationBuilder.Build())),
			new Material(glm::vec3(0.5, 0.5, 0))),
		new Light(glm::vec3(1, 1, 1))));
}