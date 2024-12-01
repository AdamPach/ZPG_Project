#include "FourSpheresScene.h"

#include "../../shaders/ShaderProgram.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/models/normaled/SphereObject.h"
#include "../../objects/drawable/SimpleDrawableObject.h"
#include "../../objects/drawable/MaterialDrawableObjectDecorator.h"
#include "../../objects/drawable/LightDrawableObjectDecorator.h"
#include "../../objects/models/normaled/SuziSmoothModel.h"
#include "../../objects/models/normaled/PlainModel.h"
#include "../../objects/EmptyModel.h"
#include "../lights/PointLight.h"


FourSpheresScene::FourSpheresScene() : Scene()
{
}

void FourSpheresScene::InitShaders()
{
	ShaderProgramBuilder shaderBuilder;

	shaderBuilder.AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_phong.vert")
		->AddTransformationUniform("modelMatrix")
		->AddMaterialUniform(DEFAULT_MATERIAL_NAME);

	AddShaderProgram(shaderBuilder.Build(), "phong_shader");
}

void FourSpheresScene::InitScene()
{
	auto shaderProgram = GetShaderProgram("phong_shader");

	UseCameraPosition();

	TransformationsBuilder transformationBuilder;

	auto baseTransformation = transformationBuilder.AddScale(0.5f)->AddTranslation(0, 0, -1)->Build();

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(-1, 0, 0);

	auto material = (new Material())->SetColor(glm::vec3(0.8f, 0, 0))->SetAmbient(0.1f)->SetSpecular(1);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())), material));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(1, 0, 0);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())), material));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(0, -1, 0);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())), material));

	transformationBuilder.AddTransformation(baseTransformation)->AddTranslation(0, 1, 0);

	AddObject(new MaterialDrawableObjectDecorator(new SimpleDrawableObject(SphereObject::GetInstance(), shaderProgram, new Transformation(transformationBuilder.Build())), material));

	transformationBuilder.AddScale(0.01f)->AddTranslation(0, 0, -1);


	AddObject(new LightDrawableObjectDecorator(
			new SimpleDrawableObject(
				EmptyModel::GetInstance(),
				shaderProgram,
				new Transformation(transformationBuilder.Build())), 
		new PointLight(glm::vec3(1,1,1))));

}
