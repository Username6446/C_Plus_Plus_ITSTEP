#pragma once
#include "Passport.h"
class ForeignPassport : public Passport
{
private:
	string number;
	string data;
public:
	ForeignPassport() = default;
	ForeignPassport(const string& First_Name, const string& Second_Name, const string& Middle_Name,const string& number, const string& data);
	
	void setNumber(const string& number);
	void setData(const string& data);

	const string& getNumber() const;
	const string& getData() const;

	void print() const;
};

