#pragma once
#include <iostream>

using namespace std;

// не можна перевантажити операції : sizeof, typeid, ?

class Point
{
private:
	double x = 0, y = 0;
public:
	Point() = default;
	Point(const double& x) :x{ x } {};
	Point(const double& x, const double& y) : x{ x }, y{ y } {};

	void setX(const double& x);
	void setY(const double& y);

	double getX() const;
	double getY() const;

	void print() const;

	Point operator +(const Point& other) const;
	Point operator -(const Point& other) const;
	bool operator ==(const Point& other) const;
	bool operator !=(const Point& other) const;

	Point& operator ++();
	Point operator ++(int);

};

inline void Point::setX(const double& x)
{
	this->x = x;
}

inline void Point::setY(const double& y)
{
	this->y = y;
}

inline double Point::getX() const
{
	return x;
}

inline double Point::getY() const
{
	return y;
}

inline void Point::print() const
{
	cout << "(" << x << "," << y << ")" << "\t";
}