#include "Tiger.h"

Tiger::Tiger()
{
	cout << " >>>>>>>>>>>>> Ctor Tiger ID # " << id << endl;
}

Tiger::Tiger(const string& place, const size_t& age, const size_t& numOfStrings)
	:Animal(place, age), numOfStrings{ numOfStrings }
{
	cout << " >>>>>>>>>>>>> Ctor Tiger ID # " << id << endl;
}

void Tiger::print() const
{
	cout << "------------------- Tiger Id    :: " << id << endl;
	cout << "Tiger age   :: " << getAge() << endl;
	cout << "Tiger place :: " << place << endl;
	cout << "\t Tiger numOfStrings :: " << numOfStrings << endl;
}