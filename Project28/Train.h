#pragma once
#include "Car.h"
using namespace std;

class Train
{
private:
	Car* train;
	string name = "";
	size_t number = 0;
	size_t size = 0;
public:
	Train() = default;
	Train(Car* train, string name, size_t number, size_t size);
	Train(const Train& other);
	~Train();

	string getName() const;
	size_t getNumber() const;
	size_t getSize() const;

	void setName(string name);
	void setNumber(size_t number);
	void setSize(size_t size);

	int AllNumOfPassengers();

	friend int MaxNumOfPassengers(Car car);

	friend std::ostream& operator << (std::ostream& out, const Car& obj);
	friend std::istream& operator >> (std::istream& in, const Car& obj);

};

