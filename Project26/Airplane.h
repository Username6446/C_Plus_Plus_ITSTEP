#pragma once
#include <cstring>
#include <iostream>

using namespace std;

const int SIZE = 50;

class Airplane
{
private:
	char* Type = nullptr;
	int MaxPassengers = 0;
	int Passengers = 0;
public:
	Airplane() = default;
	Airplane(const char* Type, int MaxPassengers, int Passengers);

	void setType(const char* Type);
	void setMaxPassengers(int MaxPassengers);
	void setPassengers(int Passengers);

	bool operator==(const Airplane other);
	Airplane& operator++();
	Airplane& operator--();
	bool operator>(const Airplane other);

	void print() const;
};


inline void Airplane::setMaxPassengers(int MaxPassengers)
{
	this->MaxPassengers = MaxPassengers;
}

inline void Airplane::setPassengers(int Passengers)
{
	this->Passengers = Passengers;
}

