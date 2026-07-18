#pragma once

class Square {
protected:
    double side;

public:
    Square(double s = 0);
    virtual ~Square();

    double getSquareSquare() const;
    double getSquareLength() const;

    void setSide(double s);
    double getSide() const;
};