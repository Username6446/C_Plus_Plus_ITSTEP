#include "Car.h"

Car::Car(string type, size_t numOfPassengers) :type{ type }, numOfPassengers{numOfPassengers}
{
}

string Car::getType() const
{
	return type;
}

size_t Car::getNumOfPassengers() const
{
	return numOfPassengers;
}

void Car::setType(string type)
{
	this->type = type;
}

void Car::setNumOfPassengers(size_t numOfPassengers)
{
	this->numOfPassengers = numOfPassengers;
}

void Car::print() const
{
	cout << "Type :: " << type << "Num of passengers :: " << numOfPassengers;
}

std::ostream& operator<<(std::ostream& out, const Car& obj)
{
	out << "Type :: " << obj.type << "Num of passengers :: " << obj.numOfPassengers;
	return out;
}

std::istream& operator>>(std::istream& in, Car& obj)
{
	cout << "Type :: ";
	in >> obj.type;
	cout << "Num of passengers :: ";
	in >> obj.numOfPassengers;
	return in;
}
