#pragma once
#include "Pet.h"
class Parrot : public Pet {
private:
    bool canSpeak; 

public:
    Parrot(string n, bool speak) : Pet(n), canSpeak(speak) {}

    void ShowInfo() const override {
        cout << "[Parrot] ";
        Pet::ShowInfo();
        cout << ", Can say : " << (canSpeak ? "Yes" : "No") << endl;
    }

    void Voice() const override {
        if (canSpeak)
            cout << name << " say: Hello!" << endl;
        else
            cout << name << " say ..." << endl;
    }
};