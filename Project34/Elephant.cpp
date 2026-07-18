#include "Elephant.h"

Elephant::Elephant()
{
	cout << " >>>>>>>>>>>>> Ctor Elephant ID # " << id << endl;

}

Elephant::Elephant(const string& place, const size_t& age, const double& mass)
	:Animal(place, age), mass{ mass }
{
	cout << " >>>>>>>>>>>>> Ctor Elephant ID # " << id << endl;
}

void Elephant::print() const
{
	cout << "------------------- Elephant Id    :: " << id << endl;
	cout << "Elephant age   :: " << getAge() << endl;
	cout << "Elephant place :: " << place << endl;
	cout << "\t Elephant mass :: " << mass << endl;
}