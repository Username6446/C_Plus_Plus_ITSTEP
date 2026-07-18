#include "ForeignPassport.h"

ForeignPassport::ForeignPassport(const string& First_Name, const string& Second_Name, const string& Middle_Name, const string& number, const string& data)
    :Passport(First_Name, Second_Name, Middle_Name)
{
    setNumber(number);
    setData(data);
}

void ForeignPassport::setNumber(const string& number)
{
    this->number = number;
}

void ForeignPassport::setData(const string& data)
{
    this->data = data;
}

const string& ForeignPassport::getNumber() const
{
    return number;
}

const string& ForeignPassport::getData() const
{
    return data;
}

void ForeignPassport::print() const
{
    cout << "\t\tForeignPassport\t\t" << endl;
    cout << "First_Name :: " << getFirst_Name() << endl;
    cout << "Second_Name :: " << getSecond_Name() << endl;
    cout << "Middle_Name :: " << getMiddle_Name() << endl;
    cout << "Number :: " << number << endl;
    cout << "Data :: " << data << endl;
}