#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Vector
{
private:
	int* buffer = nullptr;
	size_t capacity = 0;
	size_t size = 0;
public:
	Vector() = default;
	Vector(size_t size);
	Vector(size_t size, int value);
	Vector(const Vector& other);
	~Vector();
	size_t getCapacity() const;
	size_t getSize() const;
	bool IsEmpty() const;
	void setValue(int index, int value);
	int getElement(int index) const;
	void pushBack(int element);
	void pushFront(int element);
	void popBack();
	void popFront();
	int& front();
	int& back();
	void pushIndex(int index, int element);
	void popIndex(int index);
	void clear();
	void reserve(size_t newCapacity);
	void resize(size_t newSize, int value = 0);
	void print() const;

	Vector operator+ (const Vector& other) const;
	Vector operator- (const Vector& other) const;
	Vector operator* (const size_t& n) const;
	explicit operator int() const;
	explicit operator char* () const;
};

