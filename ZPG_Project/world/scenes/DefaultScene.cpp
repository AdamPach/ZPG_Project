#include "DefaultScene.h"
#include "../../defaults.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/abstraction/TriangleNormalModel.h"
#include "../../objects/models/cube_only_points.h"
#include "../../objects/abstraction/PositionModel.h"
#include "../../objects/drawable/TextureDrawableObjectDecorator.h"
#include "../../objects/textures/TexturesManager.h"

float triangleVertices[] = {
	-0.5f, -0.5f, 0.0f, 0.73f, 0.18f, 0.66f,
	0.5f, -0.5f, 0.0f, 0.73f, 0.18f, 0.66f,
	0.0f, 0.5f, 0.0f, 0.73f, 0.18f, 0.66f
};

DefaultScene::DefaultScene() : Scene()
{
}

void DefaultScene::InitShaders()
{
	auto shaderBuilder = ShaderProgramBuilder();

	shaderBuilder.AddVertexShader("vertext_position_color.vert")
		->AddFragmentShader("fragment_position_color.vert")
		->AddTransformationUniform("modelMatrix");

	AddShaderProgram(shaderBuilder.Build(), "basic_shader");

	shaderBuilder.AddVertexShader("vertext_position_cubemap.vert")
		->AddFragmentShader("fragment_position_cubemap.vert")
		->AddTransformationUniform(DEFAULT_MODEL_MATRIX_NAME)
		->AddTextureUnitUniform(DEFAULT_TEXTURE_UNIT_NAME);

	AddShaderProgram(shaderBuilder.Build(), "cubemap_shader");
}

void DefaultScene::InitScene()
{
	auto color_shader_program = GetShaderProgram("basic_shader");
	auto cubemap_shader_program = GetShaderProgram("cubemap_shader");

	TransformationsBuilder transformationBuilder;

	TriangleNormalModel* triangleModel = new TriangleNormalModel(triangleVertices, sizeof(triangleVertices));

	AddObject(new SimpleDrawableObject(
		triangleModel,
		color_shader_program,
		new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddTranslation(1.0f, 0, 0);

	AddObject(new SimpleDrawableObject(
		triangleModel,
		color_shader_program,
		new Transformation(transformationBuilder.Build())));

	auto cubeModel = new PositionModel(cube, sizeof(cube));

	AddObject(new TextureDrawableObjectDecorator(
		new SimpleDrawableObject(
			cubeModel,
			cubemap_shader_program,
			new Transformation(transformationBuilder.Build())),
		TexturesManager::GetInstance()->GetSkycube()));
}
