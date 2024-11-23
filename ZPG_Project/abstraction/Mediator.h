#pragma once

#include "Request.h"

class Mediator
{
public:
	virtual void Send(Request * request) = 0;
};