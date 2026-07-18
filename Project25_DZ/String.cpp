#include "String.h"

int String::count = 0;

String::String()
{
	size = 80;
	length = 0;
	str = new char[size];
	str[0] = '\0';
	count++;
}

String::String(size_t size)
{
	this->size = size;
	this->length = 0;
	str = new char[size];
	str[0] = '\0';
	count++;
}

String::String(const char* str)
{
	length = 0;
	while (str[length] != '\0') 
		length++;

	this->size = length + 1;
	this->str = new char[this->size];

	for (size_t i = 0; i < length; i++) {
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
	count++;
}

String::String(const String& other)
{
	this->size = other.size;
	this->length = other.length;
	this->str = new char[this->size];

	for (size_t i = 0; i <= length; i++) {
		this->str[i] = other.str[i];
	}
	count++;
}

String::~String()
{
	if (str != nullptr) {
		delete[] str;
	}
	count--;
}

String& String::operator=(const String& other)
{
	if (this == &other) 
		return *this;

	delete[] str;

	this->size = other.size;
	this->length = other.length;
	this->str = new char[this->size];

	for (size_t i = 0; i <= length; i++) {
		this->str[i] = other.str[i];
	}

	return *this;
}

void String::input()
{
	char temp[4096];
	cout << "\nEnter String: ";
	cin.getline(temp, 4096);

	size_t newLen = 0;
	while (temp[newLen] != '\0') 
		newLen++;

	if (newLen >= size) {
		delete[] str;
		size = newLen + 1;
		str = new char[size];
	}

	length = newLen;
	for (size_t i = 0; i <= length; i++) {
		str[i] = temp[i];
	}
}

void String::output() const
{
	if (str) {
		cout << str << endl;
	}
}

String String::concat(const String& obj)
{
	size_t newLen = this->length + obj.length;
	size_t newSize = newLen + 1;

	String newStr(newSize);
	newStr.length = newLen;

	size_t i = 0;
	for (; i < this->length; i++) {
		newStr.str[i] = this->str[i];
	}
	for (size_t j = 0; j < obj.length; j++, i++) {
		newStr.str[i] = obj.str[j];
	}
	newStr.str[newLen] = '\0';

	return newStr;
}

String String::intersection(const String& obj)
{
	char temp[4096];
	size_t k = 0;

	for (size_t i = 0; i < this->length; i++) {
		bool foundInObj = false;
		for (size_t j = 0; j < obj.length; j++) {
			if (this->str[i] == obj.str[j]) {
				foundInObj = true;
				break;
			}
		}

		if (foundInObj) {
			bool alreadyAdded = false;
			for (size_t x = 0; x < k; x++) {
				if (temp[x] == this->str[i]) {
					alreadyAdded = true;
					break;
				}
			}
			if (!alreadyAdded) {
				temp[k++] = this->str[i];
			}
		}
	}
	temp[k] = '\0';

	return String(temp);
}

int String::getCount()
{
	return count;
}

int String::cmp(const String& obj1, const String& obj2)
{
	size_t minLen = (obj1.length < obj2.length) ? obj1.length : obj2.length;

	for (size_t i = 0; i < minLen; i++) {
		if (obj1.str[i] > obj2.str[i]) return 1;
		if (obj1.str[i] < obj2.str[i]) return -1;
	}

	if (obj1.length == obj2.length) return 0;
	return (obj1.length > obj2.length) ? 1 : -1;
}

void String::sort(String arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (String::cmp(arr[j], arr[j + 1]) > 0) {
				String temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}