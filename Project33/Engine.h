#pragma once
#include "iostream"
using namespace std;
class Engine
{
public:
	Engine(const string& model,const size_t& power, const double& volume) :model(model), power(power), volume(volume)
	{}
	Engine() = default;
	void print() const {
		cout << "Engine model :: " << model << "\t power :: " << power << "\t volume :: " << volume << endl;
	}

private:
	string model;
	size_t power;
	double volume;

};

