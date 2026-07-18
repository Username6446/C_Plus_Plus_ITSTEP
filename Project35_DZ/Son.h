#pragma once
#include "Daddy.h"

class Son : public Daddy {
public:
    void Sleep() override;
    void Walk() override;
    virtual void Play();
};