#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
#include "Person.h"
class Employee : virtual public Person
{
public:
	Employee(const string& name = "Noname", const string& position = "NoPosition");
	void print() const;
	~Employee();
protected:
	// string name; from Person
	string position;
};

