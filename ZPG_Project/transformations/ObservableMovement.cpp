#include "ObservableMovement.h"

ObservableMovement::ObservableMovement(TypedDataProviderSubject<glm::vec3>* positionSubject) : Translation(glm::vec3(0.0f))
{
	this->positionSubject = positionSubject;
	this->positionSubject->Subcribe(this);

	lastPosition = glm::vec3(0.0f);
	Update();
}

ObservableMovement::~ObservableMovement()
{
	this->positionSubject->Unsubcribe(this);
}

glm::mat4 ObservableMovement::GetMatrix()
{
	if (acutalPosition != lastPosition)
	{
		lastPosition = acutalPosition;
		transformationMatrix = glm::translate(glm::mat4(1.0f), acutalPosition);
	}

	return transformationMatrix;
}

void ObservableMovement::Update()
{
	acutalPosition = positionSubject->GetValue();
}

bool ObservableMovement::IsDynamic()
{
    return true;
}
