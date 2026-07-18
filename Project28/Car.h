#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
	string type = "";
	size_t numOfPassengers = 0;
public:
	Car() = default;
	Car(string type, size_t numOfPassengers);
	
	string getType() const;
	size_t getNumOfPassengers() const;

	void setType(string type);
	void setNumOfPassengers(size_t numOfPassengers);

	void print() const;

	friend std::ostream& operator << (std::ostream& out, const Car& obj);
	friend std::istream& operator >> (std::istream& in, Car& obj);

	friend int MaxNumOfPassengers(Car car);
	friend int MinNumOfPassengers(Car car);
	

};

