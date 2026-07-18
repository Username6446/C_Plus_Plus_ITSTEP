#include "Passport.h"

Passport::Passport(const string& First_Name, const string& Second_Name, const string& Middle_Name)
{
    setFirst_Name(First_Name);
    setSecond_Name(Second_Name);
    setMiddle_Name(Middle_Name);
}

void Passport::setFirst_Name(const string& First_Name)
{
    this->First_Name = First_Name;
}

void Passport::setSecond_Name(const string& Second_Name)
{
    this->Second_Name = Second_Name;
}

void Passport::setMiddle_Name(const string& Middle_Name)
{
    this->Second_Name = Second_Name;
}

const string& Passport::getFirst_Name() const
{
    return First_Name;
}

const string& Passport::getSecond_Name() const
{
    return Second_Name;
}

const string& Passport::getMiddle_Name() const
{
    return Middle_Name;
}

void Passport::print() const
{
    cout << "\t\Passport\t\t" << endl;
    cout << "First_Name :: " << First_Name << endl;
    cout << "Second_Name :: " << Second_Name << endl;
    cout << "Middle_Name :: " << Middle_Name << endl;
}