#include "ForestScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../objects/models/normaled/PlainModel.h"
#include "../../objects/models/normaled/TreeModel.h"
#include "../../objects/models/normaled/BushesModel.h"
#include "../../objects/models/normaled/SphereObject.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/drawable/MaterialDrawableObjectDecorator.h"
#include "../../objects/drawable/TextureDrawableObjectDecorator.h"
#include "../../objects/drawable/LightDrawableObjectDecorator.h"
#include "../../transformations/ObservableMovement.h"
#include "../../objects/EmptyModel.h"
#include "../lights/SpotLight.h"
#include "../lights/PointLight.h"
#include "../../objects/textures/TexturesManager.h"
#include "../../objects/models/builder/ModelBuilder.h"

#include "../../assets/models/plain_textured.h"
#include "../../objects/models/abstraction/TriangleNormalTexturedModel.h"



ForestScene::ForestScene() : Scene()
{

}

void ForestScene::InitShaders()
{
	ShaderProgramBuilder builder;

	builder.AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_attenuation_phong.vert")
		->AddTransformationUniform(DEFAULT_MODEL_MATRIX_NAME)
		->AddMaterialUniform(DEFAULT_MATERIAL_COLOR_NAME);

	auto color_shader_program = builder.Build();

	AddShaderProgram(color_shader_program, "basic_shader");

	builder.AddVertexShader("vertext_position_normal_light_base_texture2d.vert")
		->AddFragmentShader("fragment_position_normal_attenuation_texture2d_phong.vert")
		->AddTransformationUniform(DEFAULT_MODEL_MATRIX_NAME)
		->AddMaterialUniform(DEFAULT_MATERIAL_COLOR_NAME)
		->AddTextureUnitUniform(DEFAULT_TEXTURE_UNIT_NAME);

	auto texture_shader_program = builder.Build();
	AddShaderProgram(texture_shader_program, "texture_shader");
}


void ForestScene::InitScene()
{
	auto color_shader_program = GetShaderProgram("basic_shader");
	auto texture_shader_program = GetShaderProgram("texture_shader");

	UseCameraPosition();
	
	TransformationsBuilder transformationBuilder;

	auto modelBuilder = ModelBuilder::Create();
	
	auto texture = modelBuilder->FromPoints(plain_textured, sizeof(plain_textured))
		->HasPosition()
		->HasNormals()
		->HasTextureCoordinates()
		->Build();

	for (int x = -10; x < 10; x++)
	{
		for (int z = -10; z < 10; z++)
		{
			transformationBuilder.AddTranslation(x * 2, -0.5f, z * 2);

			AddObject(new TextureDrawableObjectDecorator(
				new SimpleDrawableObject(
					texture,
					texture_shader_program,
					new Transformation(transformationBuilder.Build())),
				TexturesManager::GetInstance()->GetGrassTexture()));
		}
	}

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
	
	for (int i = 0; i < 95; i++)
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
			new PointLight(glm::vec3(0.2, 0.2, 0.2))));
	}
	
	transformationBuilder.AddTransformation(new ObservableMovement(GetCameraPositionSubject()));

	AddObject(new LightDrawableObjectDecorator(
		new MaterialDrawableObjectDecorator(
			new SimpleDrawableObject(
				EmptyModel::GetInstance(),
				color_shader_program,
				new Transformation(transformationBuilder.Build())),
			new Material(glm::vec3(0.5, 0.5, 0))),
		new SpotLight(GetCameraFrontSubject(), glm::vec3(1, 1, 1))));
		
	auto house = modelBuilder->FromFile("house.obj")
		->Build();

	transformationBuilder.AddScale(0.4f)
		->AddTranslation(0,-0.5f,13);

	AddObject(new TextureDrawableObjectDecorator(
		new SimpleDrawableObject(
			house,
			texture_shader_program,
			new Transformation(transformationBuilder.Build())),
		TexturesManager::GetInstance()->GetHouseTexture()));

	auto login = modelBuilder->FromFile("login.obj")
		->Build();

	transformationBuilder.AddRotation(180, Axis::Y)
		->AddTranslation(-5, -0.5f, 13);

	AddObject(new TextureDrawableObjectDecorator(
		new SimpleDrawableObject(
			login,
			texture_shader_program,
			new Transformation(transformationBuilder.Build())),
		TexturesManager::GetInstance()->GetGrassTexture()));
}