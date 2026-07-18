#pragma once
#include "Person.h"
#include <string>
using std::string;
class Student : virtual public Person
{
public:
	Student(const string& name = "Noname", const string& specialization = "Nospec");
	void print() const;
	~Student();
protected:
	// string name; from Person
	string specialization;
};

