#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Pair
{
	T data;
	int priority;
};

template <typename T>
class QueuePr
{
private:
	Pair<T>* p;
	size_t count;

public:
	QueuePr();
	QueuePr(const QueuePr& other);
	~QueuePr();

	QueuePr& operator=(const QueuePr& other);

	void push(T val, int priority);
	T pop();
	T peek() const;

	bool isEmpty() const;
	size_t getCount() const;
	void clear();
	void print() const;
};

template <typename T>
QueuePr<T>::QueuePr()
	: p(nullptr), count(0)
{
}

template <typename T>
QueuePr<T>::QueuePr(const QueuePr& other)
	: p(nullptr), count(0)
{
	*this = other;
}

template <typename T>
QueuePr<T>::~QueuePr()
{
	if (p != nullptr) {
		delete[] p;
	}
}

template <typename T>
QueuePr<T>& QueuePr<T>::operator=(const QueuePr& other)
{
	if (this == &other) return *this;

	clear();

	count = other.count;
	if (count > 0) {
		p = new Pair<T>[count];
		for (size_t i = 0; i < count; i++) {
			p[i] = other.p[i];
		}
	}
	else {
		p = nullptr;
	}

	return *this;
}

template <typename T>
void QueuePr<T>::push(T val, int priority)
{
	Pair<T>* temp = new Pair<T>[count + 1];

	size_t pos = 0;
	while (pos < count && p[pos].priority <= priority) {
		pos++;
	}

	for (size_t i = 0; i < pos; i++) {
		temp[i] = p[i];
	}

	temp[pos].data = val;
	temp[pos].priority = priority;

	for (size_t i = pos; i < count; i++) {
		temp[i + 1] = p[i];
	}

	if (p != nullptr) delete[] p;
	p = temp;
	count++;
}

template <typename T>
T QueuePr<T>::pop()
{
	if (isEmpty()) {
		cout << "Queue is empty!" << endl;
		return T();
	}

	T val = p[count - 1].data;

	if (count == 1) {
		delete[] p;
		p = nullptr;
		count = 0;
	}
	else {
		Pair<T>* temp = new Pair<T>[count - 1];
		for (size_t i = 0; i < count - 1; i++) {
			temp[i] = p[i];
		}
		delete[] p;
		p = temp;
		count--;
	}

	return val;
}

template <typename T>
T QueuePr<T>::peek() const
{
	if (isEmpty()) {
		return T();
	}	
	return p[count - 1].data;
}

template <typename T>
bool QueuePr<T>::isEmpty() const
{
	return count == 0;
}

template <typename T>
size_t QueuePr<T>::getCount() const
{
	return count;
}

template <typename T>
void QueuePr<T>::clear()
{
	if (p != nullptr) {
		delete[] p;
		p = nullptr;
	}
	count = 0;
}

template <typename T>
void QueuePr<T>::print() const
{
	cout << "Queue elements (Priority: Value): ";
	if (isEmpty()) {
		cout << "Empty";
	}
	else {
		for (size_t i = 0; i < count; i++) {
			cout << "[" << p[i].priority << ": " << p[i].data << "] ";
		}
	}
	cout << endl;
}