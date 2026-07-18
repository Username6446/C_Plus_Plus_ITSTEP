#pragma once
#include "Animal.h"
class Elephant : public Animal
{
public:
	Elephant();
	Elephant(const string& place = "No place", const size_t& age = 0, const double& mass = 0.0);
	void print() const override;
private:
	double mass;
};

