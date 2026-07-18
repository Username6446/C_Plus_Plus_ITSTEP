#include "StudentEmployee.h"

StudentEmployee::StudentEmployee(const string& name, const string& specialization, const string& position)
	:Person(name),Student("", specialization), Employee("--", position)
{

	//Employee::name = nameEmployee;
	//Student::name = nameStudent;
	//this->specialization = specialization

	cout << "\t\t >>>>>>>>>>>>>> Ctor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}

StudentEmployee::StudentEmployee(const Student& student, const Employee& employee)
	:Student(student), Employee(employee) // ctor
{
	cout << "\t\t >>>>>>>>>>>>>> Ctor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}

StudentEmployee::~StudentEmployee()
{
	cout << "\t\t >>>>>>>>>>>>>> Dtor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}

void StudentEmployee::print() const {
	cout << "Name :: \t" << name << endl;
	cout << name << "studies " << specialization << endl;
	cout << name << "work as " << position << endl;
}