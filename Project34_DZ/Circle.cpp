#include "Circle.h"
#include <cmath>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double r) : radius(r) {}

Circle::~Circle() {}

double Circle::getCircleSquare() const {
    return M_PI * radius * radius;
}

double Circle::getCircleLength() const {
    return 2 * M_PI * radius;
}

void Circle::setRadius(double r) {
    radius = r;
}

double Circle::getRadius() const {
    return radius;
}