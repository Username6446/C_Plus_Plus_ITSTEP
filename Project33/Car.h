#pragma once
#include "Engine.h"
class Car
{
public:
	Car(const string& brand, const Engine& engine, const size_t& max_speed) : brand{brand}, engine{engine}, max_speed{max_speed}
	{}
	Car(const string& brand, const string& model, const size_t& power, const double& volume, const size_t& max_speed) : brand{brand}, engine{model, power, volume}, max_speed{max_speed}
	{}
	Car() = default;

	void print() const {
		cout << "Car ---> " << brand << endl;
		engine.print();
		cout << "Max Speed ---> " << max_speed << endl; 
	}
private:
	string brand = "No Brand";
	size_t max_speed = 120;
	Engine engine{ "Default model", 200, 1.5 };
};

