#include "TexturedForestScene.h"
#include "../../objects/textures/TexturesManager.h"
#include "../../transformations/TransformationsBuilder.h"
#include "../../objects/EmptyModel.h"
#include "../../objects/drawable/LightDrawableObjectDecorator.h"
#include "../../objects/drawable/MaterialDrawableObjectDecorator.h"
#include "../../objects/drawable/SimpleDrawableObject.h"
#include "../../objects/drawable/TextureDrawableObjectDecorator.h"
#include "../lights/PointLight.h"
#include "../../objects/models/builder/ModelBuilder.h"


TexturedForestScene::TexturedForestScene() : SkyCubeScene(TexturesManager::GetInstance()->GetSkycube())
{
}

void TexturedForestScene::InitShaders()
{
	ShaderProgramBuilder builder;

	builder.AddVertexShader("vertext_position_normal_light_base_texture2d.vert")
		->AddFragmentShader("fragment_position_normal_texture2d_phong.vert")
		->AddTransformationUniform(DEFAULT_MODEL_MATRIX_NAME)
		->AddMaterialUniform(DEFAULT_MATERIAL_NAME)
		->AddTextureUnitUniform(DEFAULT_TEXTURE_UNIT_NAME);

	auto shader_program = builder.Build();

	AddShaderProgram(shader_program, "texture_shader");

	builder.AddVertexShader("vertext_position_normal_light_base.vert")
		->AddFragmentShader("fragment_position_normal_phong.vert")
		->AddTransformationUniform(DEFAULT_MODEL_MATRIX_NAME)
		->AddMaterialUniform(DEFAULT_MATERIAL_NAME);

	shader_program = builder.Build();

	AddShaderProgram(shader_program, "color_shader");
}

void TexturedForestScene::InitScene()
{
	auto texture_shader_program = GetShaderProgram("texture_shader");
	auto color_shader_program = GetShaderProgram("color_shader");

	UseCameraPosition();

	TransformationsBuilder transformationBuilder;

	transformationBuilder.AddTranslation(0, 5, 0);

	AddObject(new LightDrawableObjectDecorator(
		new SimpleDrawableObject(
			EmptyModel::GetInstance(),
			texture_shader_program,
			new Transformation(transformationBuilder.Build())),
		new PointLight(glm::vec3(1.0f))));

	auto modelBuilder = ModelBuilder::Create();

	defaultMaterial = new Material();

	defaultMaterial
		->SetColor(glm::vec3(0.25, 0.9, 0.25))
		->SetAmbient(0.3f)
		->SetDiffuse(0.5f)
		->SetSpecular(0.1f);

	auto teren = modelBuilder
		->FromFile("teren.obj")
		->Build();

	transformationBuilder.AddTranslation(0, -0.5f, 0);

	AddObject(new MaterialDrawableObjectDecorator(
			new SimpleDrawableObject(
				teren,
				color_shader_program,
				new Transformation(transformationBuilder.Build())),
		defaultMaterial));
	
	auto house = modelBuilder
		->FromFile("house.obj")
		->Build();

	transformationBuilder.AddTranslation(0, -0.25f, -25.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				house,
				texture_shader_program,
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetHouseTexture()),
		defaultMaterial));

	tree = modelBuilder
		->FromFile("tree.obj")
		->Build();

	transformationBuilder.AddScale(0.2f)
		->AddTranslation(0, -0.5f, 25.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				tree,
				texture_shader_program, 
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetTreeTexture()),
		defaultMaterial));

	transformationBuilder.AddScale(0.2f)
		->AddTranslation(7, -0.5f, 18.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				tree,
				texture_shader_program,
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetTreeTexture()),
		defaultMaterial));

	transformationBuilder.AddScale(0.2f)
		->AddTranslation(-3, -0.5f, 24.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				tree,
				texture_shader_program,
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetTreeTexture()),
		defaultMaterial));

	transformationBuilder.AddScale(0.2f)
		->AddTranslation(4, -0.5f, 22.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				tree,
				texture_shader_program,
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetTreeTexture()),
		defaultMaterial));

	transformationBuilder.AddScale(0.2f)
		->AddTranslation(-8, -0.5f, -22.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				tree,
				texture_shader_program,
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetTreeTexture()),
		defaultMaterial));

	transformationBuilder.AddScale(0.2f)
		->AddTranslation(9, -0.5f, -18.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				tree,
				texture_shader_program,
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetTreeTexture()),
		defaultMaterial));

	transformationBuilder.AddScale(0.2f)
		->AddTranslation(-5, -0.5f, -14.0f);

	AddObject(new MaterialDrawableObjectDecorator(
		new TextureDrawableObjectDecorator(
			new SimpleDrawableObject(
				tree,
				texture_shader_program,
				new Transformation(transformationBuilder.Build())),
			TexturesManager::GetInstance()->GetTreeTexture()),
		defaultMaterial));
}

void TexturedForestScene::HandleRequest(MouseClickedReactionRequest request)
{

	if (request.GetButton() == MouseClickedReactionRequest::LEFT)
	{
		GLuint id;

		glReadPixels(request.GetX(), request.GetY(), 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &id);

		RemoveObject(id);

		return;
	}
	else if (request.GetButton() == MouseClickedReactionRequest::RIGHT)
	{
		GLfloat depth;
		GLuint index;

		glReadPixels(request.GetX(), request.GetY(), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
		glReadPixels(request.GetX(), request.GetY(), 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

		glm::vec3 screenX = glm::vec3(request.GetX(), request.GetY(), depth);

		glm::vec4 viewport = glm::vec4(0, 0, WindowSizeHandler::GetInstance()->GetWidth(), WindowSizeHandler::GetInstance()->GetHeight());

		glm::vec3 pos = glm::unProject(screenX, GetViewMatrix(), GetProjectionMatrix(), viewport);

		auto treeMaterial = (new Material())->SetColor(glm::vec3(0, 0.5, 0))->SetAmbient(0.05f);

		Material* defaulMaterial = new Material();

		defaulMaterial
			->SetColor(glm::vec3(0.25, 0.9, 0.25))
			->SetAmbient(0.3f)
			->SetDiffuse(0.5f)
			->SetSpecular(0.1f);

		TransformationsBuilder transformationBuilder;

		transformationBuilder.AddScale(0.15f)->AddTranslation(pos.x, pos.y, pos.z);

		AddObject(new MaterialDrawableObjectDecorator(
			new TextureDrawableObjectDecorator(
				new SimpleDrawableObject(
					tree,
					GetShaderProgram("texture_shader"),
					new Transformation(transformationBuilder.Build())),
				TexturesManager::GetInstance()->GetTreeTexture()),
			defaulMaterial));
	}
}
