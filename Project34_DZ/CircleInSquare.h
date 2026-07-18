#pragma once
#include "Circle.h"
#include "Square.h"

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(double r);
    ~CircleInSquare();

    double getTotalLength() const;
    double getEmptyArea() const;

    void setFigureRadius(double r);
    void setFigureSide(double s);

    void printInfo() const;
};