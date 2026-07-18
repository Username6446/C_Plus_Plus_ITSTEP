#pragma once
#include <cmath>

class CountArea {
private:
	static size_t counter; 
public:

	static double squareArea(const double a);
	static double rectangleArea(const double a, const double b); 
	static double diamondArea(const double d1, const double d2); 
	static double triangleArea(const double a, const double h);
	static double triangleArea(const int a, const int b, const int c);
	static double triangleArea(const double a, const double b, const double corner);
	static size_t getCounter();
};

inline double CountArea::squareArea(const double a)
{
	counter++;
	return a * a;
}

inline double CountArea::rectangleArea(const double a, const double b)
{
	counter++;
	return a * b;
}

inline double CountArea::diamondArea(const double d1, const double d2)
{
	counter++;
	return 0.5 * d1 * d2; 
}

inline double CountArea::triangleArea(const double a, const double h)
{
	counter++;
	return 0.5 * a * h;
}

inline double CountArea::triangleArea(const int a, const int b, const int c)
{
	double p = (a + b + c) / 2.0;
	counter++;
	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

inline double CountArea::triangleArea(const double a, const double b, const double corner)
{
	double corner_radians = corner * (3.14 / 180.0);
	counter++;
	return 0.5 * a * b * sin(corner_radians);
}

inline size_t CountArea::getCounter() {
	return counter;
}