#pragma once

#include "Request.h"

template <typename T>
class RequestHandler
{
public:
	virtual void HandleRequest(T request) = 0;
};