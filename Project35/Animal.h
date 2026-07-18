#pragma once
#include "lib.h"

class Animal 
{
public:
	void setPlace(const string& place);
	void setAge(const size_t& age);

	const string& getPlace() const;
	const size_t& getAge() const;

	virtual void print() const = 0; // pure virtual
	virtual void eat() const = 0;
	virtual void move() const = 0;
	Animal(const string& place = "No place", const size_t& age = 0);
	~Animal();
private:
	size_t age;
	static size_t last_id;
protected:
	size_t id;
	string place;


};

