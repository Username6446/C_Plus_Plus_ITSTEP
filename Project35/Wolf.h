#pragma once
#include "Animal.h"
class Wolf : public Animal
{
private:
	size_t weight;
public:
	Wolf(const string& place = "No place", const size_t& age = 0, const size_t& weight = 0);
	~Wolf();
	void print() const override;


	// Inherited via Animal
	void eat() const override;

	void move() const override;

};

class BlueWolf :public Wolf
{
public:
	void print() const
	{
		cout << "------------------- Blue Wolf Id    :: " << id << endl;
		cout << "Animal age   :: " << getAge() << endl;
		cout << "Animal place :: " << place << endl;
		//cout << "\t Animal weight :: " << weight << endl;
	}
};