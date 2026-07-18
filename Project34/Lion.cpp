#include "Lion.h"

void Lion::print() const
{
	cout << "------------------- Lion Id    :: " << id << endl;
	cout << "Age      :: " << getAge() << endl;
	cout << "Place    :: " << getPlace() << endl;
	cout << "Is alone :: " << isAlone << endl;
}

void Lion::eat() const {
	cout << "Lion id :: " << id << "like eat meat" << endl;
}


Lion::Lion(const string& place, const size_t& age, bool isAlone) : Animal(place, age), isAlone(isAlone)
{
	//setAge(age);
	//setPlace(place);
	//isAlone = isAlone;
	cout << " >>>>>>>>>>>>> Ctor Lion ID # " << id << endl;
}

Lion::~Lion()
{
	cout << " >>>>>>>>>>>>> Dtor Lion ID # " << id << endl;

}


