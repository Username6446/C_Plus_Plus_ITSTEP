#include "Wolf.h"

Wolf::Wolf(const string& place, const size_t& age, const size_t& weight)
	: Animal(place, age), weight{weight}
{ 
	cout << " >>>>>>>>>>>>> Ctor Wolf ID # " << id << endl;
}

Wolf::~Wolf()
{
	cout << " >>>>>>>>>>>>> Dtor Wolf ID # " << id << endl;
}

void Wolf::print() const
{
	Animal::print();
	cout << "\t Animal weight :: " << weight << endl;
}