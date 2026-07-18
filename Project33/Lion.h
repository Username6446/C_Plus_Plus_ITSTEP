#pragma once
#include "Animal.h"
class Lion : public Animal
{
public:
	void print() const;
	Lion(const string& place = "No place", const size_t& age = 0, bool isAlone = 0);
	~Lion();
private:
	bool isAlone;
};

