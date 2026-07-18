#pragma once

class Circle {
protected:
    double radius;

public:
    Circle(double r = 0);
    virtual ~Circle();

    double getCircleSquare() const;
    double getCircleLength() const;

    void setRadius(double r);
    double getRadius() const;
};