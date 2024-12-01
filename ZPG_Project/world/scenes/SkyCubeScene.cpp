#include "SkyCubeScene.h"
#include "../../objects/drawable/TextureDrawableObjectDecorator.h"
#include "../../assets/models/cube_only_points.h"
#include "../../objects/models/abstraction/PositionModel.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../transformations/ObservableOffMovement.h"

SkyCubeScene::SkyCubeScene(TextureCubeMap* skyCube_texture)
{
	auto cubeModel = new PositionModel(cube, sizeof(cube));

	ShaderProgramBuilder shaderBuilder;

	shaderBuilder.AddVertexShader("vertext_position_cubemap.vert")
		->AddFragmentShader("fragment_position_cubemap.vert")
		->AddTransformationUniform(DEFAULT_MODEL_MATRIX_NAME)
		->AddTextureUnitUniform(DEFAULT_TEXTURE_UNIT_NAME);

	auto cubemap_shader_program = shaderBuilder.Build();

	AddShaderProgram(cubemap_shader_program, "cubemap_shader");

	TransformationsBuilder transformationBuilder;

	observableOffMovement = new ObservableOffMovement(GetCameraPositionSubject());

	transformationBuilder.AddTransformation(observableOffMovement);

	skyCube = new TextureDrawableObjectDecorator(
		new SimpleDrawableObject(
			cubeModel,
			cubemap_shader_program,
			new Transformation(transformationBuilder.Build())),
		skyCube_texture);
}

void SkyCubeScene::Draw()
{
	skyCube->Draw();

	glClear(GL_DEPTH_BUFFER_BIT);

	Scene::Draw();
}

InputMediator* SkyCubeScene::GetInputMediator(Application* application)
{
	auto inputMediator = Scene::GetInputMediator(application);

	inputMediator->SetSwitchObservingHandler(observableOffMovement);

	return inputMediator;
}
