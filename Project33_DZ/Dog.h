#pragma once
#include "Pet.h"
class Dog : public Pet {
private:
    string breed; 
public:

    Dog(string n, string b) : Pet(n), breed(b) {}

    void ShowInfo() const override {
        cout << "[Dog] ";
        Pet::ShowInfo();
        cout << ", Breed: " << breed << endl;
    }

    void Voice() const override {
        cout << name << " say gaf gaf!" << endl;
    }
};
