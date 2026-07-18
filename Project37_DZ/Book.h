#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator> 

using namespace std;
class Book
{
	string author;
	string name;
	size_t year;
	bool available;
	friend class Library;

public:
	Book(const string& author = "None", const string& name = "None", const size_t& year = 0, const bool& available = false) :
		author{ author }, name{ name }, year{ year }, available{ available }
	{
	}
	friend std::ostream& operator << (std::ostream& out, const Book& obj); // cout << obj
	string getName() const { return name; }
	string getAuthor() const { return author; }
	bool isAvailable() const { return available; }
};

inline std::ostream& operator<<(std::ostream& out, const Book& obj)
{
	out << "\n";
	out << "\t Title     :: " << obj.name << "\n";
	out << "\t Author    :: " << obj.author << "\n";
	out << "\t Year      :: " << obj.year << "\n";
	out << "\t Available :: " << std::boolalpha << obj.available << "\n";
	return out;
}