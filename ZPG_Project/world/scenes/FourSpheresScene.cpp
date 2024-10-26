#include "FourSpheresScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/SphereObject.h"

FourSpheresScene::FourSpheresScene(KeyboardHandler* keyboardHander, MouseHandler* mouseHandler) : Scene(keyboardHander, mouseHandler)
{
}

Scene* FourSpheresScene::InitScene()
{
	auto shaderBuilder = ShaderProgram::CreateBuilder();

	shaderBuilder->AddVertexShader("vertext_position_normal__phong_static-light.vert")
		->AddFragmentShader("fragment_position_normal_phong_static-light.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix");

	auto shaderProgram = shaderBuilder->Build();

	AddShaderProgram(shaderProgram);

	UseLight(0, 0, -1);

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
	

	return this;
}
