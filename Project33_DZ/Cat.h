#pragma once
#include "Pet.h"
class Cat : public Pet
{
	string color;
public:
    Cat(string n, string c) : Pet(n), color(c) {}

    void ShowInfo() const override {
        cout << "[Cat]  ";
        Pet::ShowInfo();
        cout << ", Color: " << color << endl;
    }

    void Voice() const override {
        cout << name << " say myo!" << endl;
    }
};
