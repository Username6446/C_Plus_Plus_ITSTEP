#include <iostream>
using std::cout;
using std::endl;
using std::cin;

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data{ data }, next{ next }
	{
	}
};

template <typename T>
class FwdList
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;

public:
	FwdList() = default;

	FwdList(const FwdList& other) {
		Node<T>* temp = other.head;
		while (temp != nullptr) {
			AddToTail(temp->data);
			temp = temp->next;
		}
	}

	~FwdList();
	void addHead(const T& data);
	void print() const;
	bool isEmpty() const;
	void removeHead();
	void removeTail();
	void AddToTail(const T& data);
	void DeleteAll();

	FwdList<T> clone() const;
	FwdList<T> operator+(const FwdList<T>& other) const;
	FwdList<T> operator*(const FwdList<T>& other) const;
};

template<typename T>
inline FwdList<T>::~FwdList()
{
	DeleteAll();
}

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (isEmpty())
		tail = tmp;
	head = tmp;
	size++;
}

template<typename T>
inline void FwdList<T>::print() const
{
	if (isEmpty()) {
		cout << "List is Empty" << endl;
		return;
	}
	auto tmp = head;
	cout << "List: ";
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline bool FwdList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (isEmpty()) {
		return;
	}
	auto tmp = head;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	--size;
	delete tmp;
}

template<typename T>
inline void FwdList<T>::removeTail()
{
	if (isEmpty()) {
		return;
	}

	if (head == tail) {
		delete head;
		head = tail = nullptr;
		size = 0;
		return;
	}

	auto tmp = head;
	while (tmp->next != tail)
	{
		tmp = tmp->next;
	}
	delete tail;
	tail = tmp;
	tail->next = nullptr;
	--size;
}

template<typename T>
inline void FwdList<T>::AddToTail(const T& data)
{
	Node<T>* tmp = new Node<T>(data, nullptr);
	if (isEmpty()) {
		head = tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tmp;
	}
	size++;
}

template<typename T>
inline void FwdList<T>::DeleteAll()
{
	while (!isEmpty())
	{
		removeHead();
	}
}

template<typename T>
inline FwdList<T> FwdList<T>::clone() const
{
	FwdList<T> newList;
	Node<T>* current = head;
	while (current != nullptr) {
		newList.AddToTail(current->data);
		current = current->next;
	}
	return newList;
}

template<typename T>
inline FwdList<T> FwdList<T>::operator+(const FwdList<T>& other) const
{
	FwdList<T> newList = this->clone();

	Node<T>* current = other.head;
	while (current != nullptr) {
		newList.AddToTail(current->data);
		current = current->next;
	}

	return newList;
}

template<typename T>
inline FwdList<T> FwdList<T>::operator*(const FwdList<T>& other) const
{
	FwdList<T> newList;
	Node<T>* currentA = head;

	while (currentA != nullptr) {
		bool foundInOther = false;

		Node<T>* currentB = other.head;
		while (currentB != nullptr) {
			if (currentB->data == currentA->data) {
				foundInOther = true;
				break;
			}
			currentB = currentB->next;
		}

		if (foundInOther) {
			bool alreadyInResult = false;
			Node<T>* resCheck = newList.head;
			while (resCheck != nullptr) {
				if (resCheck->data == currentA->data) {
					alreadyInResult = true;
					break;
				}
				resCheck = resCheck->next;
			}

			if (!alreadyInResult) {
				newList.AddToTail(currentA->data);
			}
		}
		currentA = currentA->next;
	}
	return newList;
}

