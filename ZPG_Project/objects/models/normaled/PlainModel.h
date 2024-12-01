#pragma once

#include "../abstraction/TriangleNormalModel.h"

class PlainModel : public TriangleNormalModel
{
private:
    PlainModel();
    static PlainModel* instance;

public:
    static PlainModel* GetInstance();
};

