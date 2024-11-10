#include "FourSpheresScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/SphereObject.h"
#include "../../objects/drawable/SimpleDrawableObject.h"
#include "../../objects/drawable/MaterialDrawableObjectDecorator.h"
#include "../../objects/drawable/LightDrawableObjectDecorator.h"

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
		->AddProjectionUniform("projectionMatrix")
		->AddMaterialColorUniform(DEFAULT_MATERIAL_COLOR_NAME);

	AddShaderProgram(shaderBuilder->Build(), "phong_shader");

	shaderBuilder->AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_lambert.vert")
		->AddTransformationUniform("modelMatrix")
		->AddViewUniform("viewMatrix")
		->AddProjectionUniform("projectionMatrix")
		->AddMaterialColorUniform(DEFAULT_MATERIAL_COLOR_NAME);

	AddShaderProgram(shaderBuilder->Build(), "lambert_shader");

	delete shaderBuilder;
}

void FourSpheresScene::InitScene()
{
	auto shaderProgram = GetShaderProgram("phong_shader");
	auto lambertShaderProgram = GetShaderProgram("lambert_shader");

	UseCameraPosition();

	TransformationsBuilder transformationBuilder;

	auto baseTransformation = transformationBuilder.AddScale(0.5f)->AddTranslation(0, 0, -1)->Build();

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(-1, 0, 0);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())), new Material(glm::vec3(0.8f, 0, 0))));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(1, 0, 0);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())), new Material(glm::vec3(0.3f, 0.5f, 0))));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(0, -1, 0);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())), new Material(glm::vec3(0, 0.8f, 0.3f))));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(0, 1, 0);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), lambertShaderProgram, new Transformation(transformationBuilder.Build())), new Material(glm::vec3(0.8f, 0, 0.8f))));

	transformationBuilder.AddScale(0.01f)->AddTranslation(0, 0, -1);

	AddObject(new LightDrawableObjectDecorator(
		new MaterialDrawableObjectDecorator(
			new SimpleDrawableObject(
				SphereObject::GetInstance(),
				shaderProgram,
				new Transformation(transformationBuilder.Build())),
			new Material(glm::vec3(0.8f, 0, 0.8f))), 
		new Light(glm::vec3(1,1,1))));

	transformationBuilder.AddScale(0.01f)->AddTranslation(1, 1, -1);

	AddObject(new LightDrawableObjectDecorator(
		new MaterialDrawableObjectDecorator(
			new SimpleDrawableObject(
				SphereObject::GetInstance(),
				shaderProgram,
				new Transformation(transformationBuilder.Build())),
			new Material(glm::vec3(0.8f, 0, 0.8f))),
		new Light(glm::vec3(1, 1, 1))));

}
