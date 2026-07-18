#include <iostream>
#include "Food.h"

using namespace std;

// .h ===> struct(class) definition (property, methods) + realisationof inline
// .cpp ===> realization of notinline 
// main.cpp 

int main()
{
    Food food;
    food.setName("Bread");
    food.setKkal(200);
    food.setWeight(150);

    food.print();

    Food olivie("Salad Olivie", 330, 200);
    olivie.print();

    Food clone = food; // ctor {compile create copy shallow copy}
    cout << "============ Original ============" << endl;
    food.print();
    cout << "============ Clone ============" << endl;
    clone.print();

    clone.setName("Vareniki");

    cout << "============ Original ============" << endl;
    food.print();
    cout << "============ Clone ============" << endl;
    clone.print();

    clone = olivie;
    cout << "\n\n";
    cout << "============ Original ============" << endl;
    olivie.print();
    cout << "============ Clone ============" << endl;
    clone.print();

    clone.setName("Milk");
    cout << "\n\n";
    cout << "============ Original ============" << endl;
    olivie.print();
    cout << "============ Clone ============" << endl;
    clone.print();
}
