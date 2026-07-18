#pragma once
#include "Animal.h"
class Wolf : public Animal
{
private:
	size_t weight;
public:
	Wolf(const string& place = "No place", const size_t& age = 0, const size_t& weight = 0);
	~Wolf();
	void print() const;

};

