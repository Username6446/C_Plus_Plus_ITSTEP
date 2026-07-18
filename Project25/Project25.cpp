#include <iostream>
#include "Product.h"
#include "CountArea.h"

using namespace std;

size_t CountArea::counter = 0;

int main()
{

    //cout << Product::MAX_QUANTITY << endl;

    //Product milk("Milk", 50, 3, ProductType::DAIRY);
    //milk.print();

    //cout << milk.MAX_QUANTITY << endl;

    //Product bread("Bread", 25, 10, ProductType::BAKERY);
    //bread.print();
    //cout << bread.MAX_QUANTITY << endl;

    //cout << "Number of products :: " << Product::getCounter() << endl;
    //cout << boolalpha << "Check category :: " << Product::sameTypeProduct(milk, bread) << endl;

    //Product yogurt("Berry yogurt", 40, 55, ProductType::DAIRY);
    //yogurt.print();

    //cout << "Number of products :: " << Product::getCounter() << endl;
    //cout << boolalpha << "Check category :: " << Product::sameTypeProduct(milk, yogurt) << endl;
    
    cout << CountArea::getCounter() << endl;
    cout << CountArea::rectangleArea(12.0, 5.0) << endl;
    cout << CountArea::getCounter() << endl;
    cout <<  CountArea::triangleArea(7.5, 4.0) << endl;
    cout << CountArea::getCounter() << endl;
    cout << CountArea::triangleArea(3, 4, 5) << endl;
    cout << CountArea::getCounter() << endl;
    double a = 10.0;
    double b = 8.0;
    double corner_degrees = 30.0;

    cout << CountArea::triangleArea(a, b, corner_degrees) << endl;
    cout << CountArea::getCounter() << endl;
    return 0;

}

