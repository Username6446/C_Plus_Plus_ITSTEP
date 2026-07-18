#include "CircleInSquare.h"
#include <iostream>

using namespace std;

CircleInSquare::CircleInSquare(double r) : Circle(r), Square(2.0 * r) {}

CircleInSquare::~CircleInSquare() {}

double CircleInSquare::getTotalLength() const {
    return getCircleLength() + getSquareLength();
}

double CircleInSquare::getEmptyArea() const {
    return getSquareSquare() - getCircleSquare();
}

void CircleInSquare::setFigureRadius(double r) {
    cout << "-> Changing radius to " << r << "..." << endl;
    this->radius = r;
    this->side = 2.0 * r;
}

void CircleInSquare::setFigureSide(double s) {
    cout << "-> Changing square side to " << s << "..." << endl;
    this->side = s;
    this->radius = s / 2.0;
}

void CircleInSquare::printInfo() const {
    cout << "====================================" << endl;
    cout << "Figure: Circle inscribed in Square" << endl;
    cout << "Circle radius: " << radius << endl;
    cout << "Square side:   " << side << endl;
    cout << "Circle area:   " << getCircleSquare() << endl;
    cout << "Square area:   " << getSquareSquare() << endl;
    cout << "Area difference (empty corners): " << getEmptyArea() << endl;
    cout << "Total length (perimeter): " << getTotalLength() << endl;
    cout << "====================================" << endl;
}