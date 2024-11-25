#pragma once

#include "Translation.h"
#include "../abstraction/UnifromVariableSubject.h"

class ObservableMovement : public Observer, public Translation
{
public:
	ObservableMovement(TypedDataProviderSubject<glm::vec3>* positionSubject);
	~ObservableMovement();

	glm::mat4 GetMatrix() override;
	virtual void Update() override;
	bool IsDynamic() override;
private:
	TypedDataProviderSubject<glm::vec3>* positionSubject;
	glm::vec3 acutalPosition, lastPosition;
};