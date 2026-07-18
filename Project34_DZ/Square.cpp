#include "Square.h"

Square::Square(double s) : side(s) {}

Square::~Square() {}

double Square::getSquareSquare() const {
    return side * side;
}

double Square::getSquareLength() const {
    return 4 * side;
}

void Square::setSide(double s) {
    side = s;
}

double Square::getSide() const {
    return side;
}