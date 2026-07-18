#include "Wolf.h"

Wolf::Wolf(const string& place, const size_t& age, const size_t& weight)
	: Animal(place, age), weight{ weight }
{
	cout << " >>>>>>>>>>>>> Ctor Wolf ID # " << id << endl;
}

Wolf::~Wolf()
{
	cout << " >>>>>>>>>>>>> Dtor Wolf ID # " << id << endl;
}

void Wolf::print() const
{
	cout << "------------------- Wolf Id    :: " << id << endl;
	cout << "Animal age   :: " << getAge() << endl;
	cout << "Animal place :: " << place << endl;
	cout << "\t Animal weight :: " << weight << endl;
}