#include "Vector.h"

Vector::Vector(size_t size)
{
	this->size = size;
	this->capacity = size * 2;
	this->buffer = new int[capacity];
}

Vector::Vector(size_t size, int value) : Vector(size)
{
	for (int i = 0; i < size; i++) {
		buffer[i] = value;
	}
}

Vector::Vector(const Vector& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->buffer = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		buffer[i] = other.buffer[i];
	}

}

Vector::~Vector()
{
	delete[] this->buffer;
}

size_t Vector::getCapacity() const
{
	return this->capacity;
}

size_t Vector::getSize() const
{
	return this->size;
}

bool Vector::IsEmpty() const
{
	if (size == 0) {
		return true;
	}
	return false;
}

void Vector::setValue(int index, int value)
{
	if (index >= 0 && index < size)
		buffer[index] = value;
	else
		cout << "Error index";
}

int Vector::getElement(int index) const
{
	if (index >= 0 && index < (int)size)
		return buffer[index];
	cout << "Error: invalid index" << endl;
	return -1;
}

void Vector::pushBack(int element)
{
	int ind = size;
	resize(size + 1);
	buffer[ind] = element;

}

void Vector::pushFront(int element)
{
	pushIndex(0, element);
}

void Vector::popBack()
{
	if (IsEmpty()) {
		cout << "Buffer is empty" << endl;
		return;
	}
	resize(size - 1);

}

void Vector::popFront()
{
	popIndex(0);
}

int& Vector::front() {
	int static errorFront = 0;
	if (IsEmpty())
		return errorFront;
	return *buffer;
}

int& Vector::back() {
	int static errorFront = 0;
	if (IsEmpty())
		return errorFront;
	return *(buffer + size - 1);
}

void Vector::pushIndex(int index, int element)
{
	if (index < 0 || index >size) return;
	if (size >= capacity)
		reserve(capacity == 0 ? 2 : capacity * 2);

	for (int i = (int)size; i > index; i--)
		buffer[i] = buffer[i - 1];

	buffer[index] = element;
	size++;
}

void Vector::popIndex(int index)
{
	if (index < 0 || index >= (int)size) return;

	for (int i = index; i < size - 1; i++) {
		buffer[i] = buffer[i + 1];
	}
	size--;
}

void Vector::clear()
{
	for (int i = 0; i < size; i++) {
		buffer[i] = 0;
	}
	resize(0);
}

void Vector::reserve(size_t newCapacity)
{
	if (newCapacity <= capacity) return;

	int* newBuffer = new int[newCapacity];
	for (size_t i = 0; i < size; i++)
		newBuffer[i] = buffer[i];

	delete[] buffer;
	buffer = newBuffer;
	capacity = newCapacity;
}


void Vector::resize(size_t newSize, int value)
{
	if (newSize > capacity)
		reserve(newSize * 2 + 1);

	if (newSize > size) {
		for (size_t i = size; i < newSize; i++)
			buffer[i] = value;
	}
	size = newSize;
}

void Vector::print() const
{
	for (int i = 0; i < size; i++) {
		cout << buffer[i] << "  ";
	}
	cout << endl;
}

Vector Vector::operator+(const Vector& other) const
{
	Vector result(0);

	for (int i = 0; i < this->size; i++) {
		result.pushBack(this->buffer[i]);
	}

	for (int i = 0; i < other.size; i++) {
		result.pushBack(other.buffer[i]);
	}

	return result;
}

Vector Vector::operator-(const Vector& other) const
{
	Vector result(0);

	for (int i = 0; i < this->size; i++) {
		bool flag = false;

		for (int j = 0; j < other.size; j++) {
			if (this->buffer[i] == other.buffer[j]) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			result.pushBack(this->buffer[i]);
		}
	}

	return result;
}

Vector Vector::operator*(const size_t& n) const
{
	Vector result(*this);

	for (int i = 0; i < result.size; i++) {
		result.buffer[i] *= n;
	}

	return result;
}

Vector::operator int() const
{
	return (int)this->size;
}

Vector::operator char* () const
{
	if (size == 0) {
		char* empty = new char[1];
		empty[0] = '\0';
		return empty;
	}

	string tempStr = "";
	for (int i = 0; i < size; i++) {
		tempStr += to_string(buffer[i]) + " ";
	}

	char* result = new char[tempStr.length() + 1];
	strcpy(result, tempStr.c_str());

	return result;
}