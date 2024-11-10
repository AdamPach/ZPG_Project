#include "DrawableObjectDecorator.h"

#include <typeinfo>

DrawableObjectDecorator::DrawableObjectDecorator(DrawableObject* drawableObject)
{
	this->drawableObject = drawableObject;
}

DrawableObjectDecorator::~DrawableObjectDecorator()
{
	delete drawableObject;
}

void DrawableObjectDecorator::Draw()
{
	drawableObject->Draw();
}

ShaderProgram* DrawableObjectDecorator::GetShader() const
{
	return drawableObject->GetShader();
}

Transformation* DrawableObjectDecorator::GetTransformation() const
{
	return drawableObject->GetTransformation();
}

Model* DrawableObjectDecorator::GetModel() const
{
	return drawableObject->GetModel();
}

template <typename T>
bool DrawableObjectDecorator::IsDecoratedBy()
{
	const DrawableObject* current = this;

	while (const DrawableObjectDecorator* decorator = dynamic_cast<const DrawableObjectDecorator*>(current))
	{
		if (typeid(*decorator) == typeid(T))
		{
			return true;
		}

		current = decorator->drawableObject;
	}

	return false;
}