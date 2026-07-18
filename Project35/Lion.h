#pragma once
#include "Animal.h"
class Lion : public Animal
{
public:
	Lion(const string& place = "No place", const size_t& age = 0, bool isAlone = 0);
	~Lion();
	void print() const override;
	void eat() const override;
	void move() const override;
private:
	bool isAlone;
};

