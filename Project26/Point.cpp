#include "Point.h"

Point Point::operator+(const Point& other) const
{
	return Point(this->x + other.x, this->y + other.y);
}
Point Point::operator-(const Point& other) const
{
	return Point(this->x - other.x, this->y - other.y);
}
bool Point::operator==(const Point& other) const
{
	return this->x == other.x and this->y == other.y;
}
bool Point::operator!=(const Point& other) const
{
	return !(*this == other);
}

Point& Point::operator++() // ++a
{
	++this->x;
	++this->y;
	return *this;
}

Point Point::operator++(int) // a++
{
	Point tmp(*this);
	/*++this->x;
	++this->y;*/
	++ *this;
	return tmp;
}
