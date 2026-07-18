#pragma once
#include "lib.h"

class Animal
{
public:
	void setPlace(const string& place);
	void setAge(const size_t& age);

	const string& getPlace() const;
	const size_t& getAge() const;

	void print() const;

	Animal(const string& place = "No place", const size_t& age = 0);
	~Animal();
private:
	size_t age;
	static size_t last_id;
protected:
	size_t id;
	string place;	


};

