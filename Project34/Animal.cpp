#include "Animal.h"


size_t Animal::last_id = 0;

void Animal::setPlace(const string& place)
{
	this->place = place;
}

void Animal::setAge(const size_t& age)
{
	this->age = age;
}

const string& Animal::getPlace() const
{
	return place;
}

const size_t& Animal::getAge() const
{
	return age;
}

void Animal::print() const
{
	cout << "Animal Id    :: " << id << endl;
	cout << "Animal age   :: " << age << endl;
	cout << "Animal place :: " << place << endl;
}

void Animal::eat() const
{
	cout << "Animal id :: " << id << "eats some food" << endl;
}

Animal::Animal(const string& place, const size_t& age)
{
	setPlace(place);
	setAge(age);
	id = ++last_id;
	cout << "Ctor Animal ID # " << id << endl;
}

Animal::~Animal()
{
	cout << "Dtor Animal ID # " << id << endl;
}
