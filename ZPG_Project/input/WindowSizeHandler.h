#pragma once

#include "../defaults.h"

#include "../abstraction/RequestHandler.h"
#include "../abstraction/UnifromVariableSubject.h"
#include "requests/WindowSizeChangedRequest.h"

class WindowSizeHandler : public RequestHandler<WindowSizeChangedRequest>, public TypedDataProviderSubject<float>
{
public:
	void HandleRequest(WindowSizeChangedRequest request) override;
	float GetValue() override;

	static WindowSizeHandler* GetInstance();
	WindowSizeHandler();
private:

	static WindowSizeHandler* instance;
};