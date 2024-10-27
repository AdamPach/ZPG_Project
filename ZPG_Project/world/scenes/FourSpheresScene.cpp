#include "FourSpheresScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/SphereObject.h"

FourSpheresScene::FourSpheresScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler) : Scene(keyboardHander, mouseHandler)
{
}

void FourSpheresScene::InitShaders()
{
	auto shaderBuilder = ShaderProgram::CreateBuilder();

	shaderBuilder->AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_phong.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	AddShaderProgram(shaderBuilder->Build(), "phong_shader");
}

void FourSpheresScene::InitScene()
{
	auto shaderProgram = GetShaderProgram("phong_shader");

	UseLight(Both);
	SetLigthPosition(0, 0, 0);
	SetLightColor(0.5, 0.647, 0.812);

	UseCameraPosition();

	TransformationsBuilder transformationBuilder;

	auto baseTransformation = transformationBuilder.AddScale(0.5f)->AddTranslation(0, 0, -1)->Build();

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(-0.8f, 0, 0);

	AddObject(new DrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(0.8f, 0, 0);

	AddObject(new DrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(0, -0.8f, 0);

	AddObject(new DrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(0, 0.8f, 0);

	AddObject(new DrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())));
}
