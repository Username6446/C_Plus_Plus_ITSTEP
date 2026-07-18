#pragma once
#include "Animal.h"
class Tiger : public Animal
{
public:
	Tiger();
	Tiger(const string& place = "No place", const size_t& age = 0, const size_t& numOfStrings = 0);
	void print() const override;
private:
	size_t numOfStrings;
};

