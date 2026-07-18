#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;

public:
    Pet(string n) : name(n) {}
    virtual ~Pet() {}

    virtual void ShowInfo() const {
        cout << "Name : " << name;
    }

    virtual void Voice() const = 0;
};

