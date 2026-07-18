#include "Food.h"


void Food::setName(const char* name)
{
	if (this->name != nullptr) {
		delete[] this->name;
	}
	size_t size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);

}

Food::Food(const char* name, const size_t& kkal, const size_t& weight)
{
	setName(name);
	setKkal(kkal);
	setWeight(weight);
}

Food::Food(const Food& other)
{
	/*this->name = other.name;*/
	setName(other.name);
	this->kkal = other.kkal;
	this->weight= other.weight;

}

void Food::operator=(const Food& other)
{
	if (this == &other) {
		return;
	}
	setName(other.name);
	setKkal(other.kkal);
	setWeight(other.weight);	
}

void Food::print() const
{
	cout << "\nFood   :: " << this->name << endl;
	cout << "Kkal   :: " << this->kkal << endl;
	cout << "Weight :: " << this->weight << endl;
}