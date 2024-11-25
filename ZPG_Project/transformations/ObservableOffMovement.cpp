#include "ObservableOffMovement.h"

ObservableOffMovement::ObservableOffMovement(TypedDataProviderSubject<glm::vec3>* positionSubject) : ObservableMovement(positionSubject)
{
	isObserving = true;
}

void ObservableOffMovement::HandleRequest(SwitchObservingRequest request)
{
	isObserving = !isObserving;
}

void ObservableOffMovement::Update()
{
	if (isObserving)
	{
		ObservableMovement::Update();
	}
}
