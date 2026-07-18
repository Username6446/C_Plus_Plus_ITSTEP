#include <iostream>
#include <typeinfo>
#include "Grandpa.h"
#include "Daddy.h"
#include "Son.h"

using namespace std;

int main() {
    const int SIZE = 3;
    Grandpa* family[SIZE];

    family[0] = new Grandpa();
    family[1] = new Daddy();
    family[2] = new Son();

    cout << "=== Processing via dynamic_cast ===" << endl;

    for (int i = 0; i < SIZE; i++) {
        Grandpa* ptr = family[i];
        cout << "Object #" << i + 1 << ":" << endl;

        if (Son* s = dynamic_cast<Son*>(ptr)) {
            s->Sleep();
            s->Walk();
            s->Play();
        }
        else if (Daddy* d = dynamic_cast<Daddy*>(ptr)) {
            d->Sleep();
            d->Walk();
        }
        else {
            ptr->Sleep();
        }
        cout << "----------------" << endl;
    }

    cout << "\n=== Processing via typeid ===" << endl;

    for (int i = 0; i < SIZE; i++) {
        Grandpa* ptr = family[i];
        cout << "Object #" << i + 1 << " (" << typeid(*ptr).name() << "):" << endl;

        if (typeid(*ptr) == typeid(Son)) {
            Son* s = static_cast<Son*>(ptr);
            s->Sleep();
            s->Walk();
            s->Play();
        }
        else if (typeid(*ptr) == typeid(Daddy)) {
            Daddy* d = static_cast<Daddy*>(ptr);
            d->Sleep();
            d->Walk();
        }
        else if (typeid(*ptr) == typeid(Grandpa)) {
            ptr->Sleep();
        }
        cout << "----------------" << endl;
    }

    for (int i = 0; i < SIZE; i++) {
        delete family[i];
    }

    return 0;
}