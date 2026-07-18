#pragma once
#include "Grandpa.h"

class Daddy : public Grandpa {
public:
    void Sleep() override;
    virtual void Walk();
};