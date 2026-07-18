#include "Airplane.h"

Airplane::Airplane(const char* Type, int MaxPassenger, int Passengers)
{
	setType(Type);
	setMaxPassengers(MaxPassenger);
	setPassengers(Passengers);
}

void Airplane::setType(const char* Type)
{
	if (this->Type != nullptr) {
		delete[] this->Type;
	}
	size_t size = strlen(Type) + 1;
	this->Type = new char[size];
	strcpy_s(this->Type, size, Type);
}

bool Airplane::operator==(const Airplane other)
{
	if (strcmp(this->Type, other.Type))
		return false;
	return true;
}


Airplane& Airplane::operator++()
{
	this->Passengers++;
	return *this;
}
Airplane& Airplane::operator--()
{
	this->Passengers--;
	return *this;
}

bool Airplane::operator>(const Airplane other)
{
	if (this->MaxPassengers > other.MaxPassengers)
		return true;
	return false;
}

void Airplane::print() const {
	cout << "\n\nType :: " << Type << endl << "MaxPassengers :: " << MaxPassengers << endl << "Passengers :: " << Passengers << "\n\n";
}