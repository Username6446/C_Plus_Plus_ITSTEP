#include "Dog.h"
#include "Parrot.h"
#include "Cat.h"
#include "vector"
int main() {

    setlocale(LC_ALL, "");

    Dog myDog("Rex", "123");
    Cat myCat("Moork", "234");
    Parrot myParrot("Pap", true);

    vector<Pet*> pets;
    pets.push_back(&myDog);
    pets.push_back(&myCat);
    pets.push_back(&myParrot);

    cout << "=== List of animals ===" << endl;

    for (const auto* pet : pets) {
        pet->ShowInfo();
        pet->Voice();
        cout << "-------------------------" << endl;
    }

    return 0;
}