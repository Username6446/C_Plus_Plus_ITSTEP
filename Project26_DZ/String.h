#pragma once
#include <iostream>

using namespace std;

class String
{
private:
	char* str = nullptr;
	size_t size = 0;
	size_t length = 0;
	static int count;

public:
	String();
	String(size_t size);
	String(const char* str);
	String(const String& other);
	~String();

	String& operator=(const String& other);

	String operator*(const String& other);
	String operator/(const String& other);
	String operator+(const String& other);

	String& operator++();
	String operator++(int);  
	bool operator>(const String& other) const;
	bool operator<(const String& other) const;
	bool operator>=(const String& other) const;
	bool operator<=(const String& other) const;
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;


	void input();
	void output() const;

	String concat(const String& obj);
	String intersection(const String& obj);

	static int getCount();
	static int cmp(const String& obj1, const String& obj2);
	static void sort(String arr[], int n);
};