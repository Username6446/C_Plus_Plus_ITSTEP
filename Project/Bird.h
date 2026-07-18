#pragma once
#include "Animal.h"

class Bird : public Animal {
public:
    Bird(string name, string species, int age);

    string getType() const override;
    void display() const override;
};