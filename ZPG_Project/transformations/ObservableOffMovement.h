#pragma once

#include "ObservableMovement.h"
#include "../abstraction/RequestHandler.h"
#include "../input/requests/SwitchObservingRequest.h"

class ObservableOffMovement : public ObservableMovement, public RequestHandler<SwitchObservingRequest>
{
public:
	ObservableOffMovement(TypedDataProviderSubject<glm::vec3>* positionSubject);

	void HandleRequest(SwitchObservingRequest request) override;
	void Update() override;
private:
	bool isObserving;
};