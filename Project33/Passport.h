#pragma once
#include "iostream"
#include <string>

using namespace std;

class Passport
{
public:
	Passport() = default;
	Passport(const string& First_Name, const string& Second_Name, const string& Middle_Name);
	void setFirst_Name(const string& First_Name);
	void setSecond_Name(const string& Second_Name);
	void setMiddle_Name(const string& Middle_Name);

	const string& getFirst_Name() const;
	const string& getSecond_Name() const;
	const string& getMiddle_Name() const;

	void print() const;
private:
	string First_Name;
	string Second_Name;
	string Middle_Name;
};

