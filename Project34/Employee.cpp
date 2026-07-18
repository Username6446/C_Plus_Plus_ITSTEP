#include "Employee.h"
#include "StudentEmployee.h"

Employee::Employee(const string& name, const string& position)
	:Person(name), position(position)
{
	cout << "\t\t >>>>>>>>>>>>>> Ctor EMPLOYEE " << this->name << endl;
}



void Employee::print() const
{
	cout << "Student name :: " << name << endl;
	cout << "Student position :: " << position << endl;
}

Employee::~Employee()
{
	cout << "\t\t >>>>>>>>>>>>>> Dtor EMPLOYEE " << this->name << endl;
}
