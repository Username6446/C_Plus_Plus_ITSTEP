#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    Node* next, * prev;
    Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
        :data{ data }, prev{ prev }, next{ next }
    {
    }
};

template<typename T>
class DList
{
public:
    DList() = default;
    ~DList();
    DList(const DList<T>& other);
    DList<T>& operator=(const DList<T>& other);

    void AddHead(const T& data);
    void AddTail(const T& data);
    void InsertAt(size_t index, const T& data);
    bool InsertAfter(const T& searchVal, const T& newData);

    void removeHead();
    void removeTail();
    void DeleteAll();
    bool removeByData(const T& data);

    size_t Replace(const T& oldVal, const T& newVal);
    void Reverse();

    void print() const;
    void printR() const;
    bool isEmpty() const { return head == nullptr; }
    bool contains(const T& data) const;

    DList<T> operator+(const DList<T>& other) const;
    DList<T> operator*(const DList<T>& other) const;

private:
    Node<T>* findNode(const T& data);
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t size = 0;
};

template<typename T>
inline DList<T>::~DList()
{
    DeleteAll();
}

template<typename T>
inline DList<T>::DList(const DList<T>& other)
{
    auto tmp = other.head;
    while (tmp != nullptr)
    {
        AddTail(tmp->data);
        tmp = tmp->next;
    }
}

template<typename T>
inline DList<T>& DList<T>::operator=(const DList<T>& other)
{
    if (this == &other) return *this;
    DeleteAll();

    auto tmp = other.head;
    while (tmp != nullptr)
    {
        AddTail(tmp->data);
        tmp = tmp->next;
    }
    return *this;
}

template<typename T>
void DList<T>::AddHead(const T& data)
{
    auto tmp = new Node<T>(data, nullptr, head);
    if (isEmpty())
        tail = tmp;
    else
        head->prev = tmp;
    head = tmp;
    ++size;
}

template<typename T>
inline void DList<T>::AddTail(const T& data)
{
    auto tmp = new Node<T>(data, tail, nullptr);
    if (isEmpty())
        head = tmp;
    else
        tail->next = tmp;
    tail = tmp;
    ++size;
}

template<typename T>
inline void DList<T>::InsertAt(size_t index, const T& data)
{
    if (index > size) return;
    if (index == 0) {
        AddHead(data);
        return;
    }
    if (index == size) {
        AddTail(data);
        return;
    }

    Node<T>* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    Node<T>* newNode = new Node<T>(data, current->prev, current);
    current->prev->next = newNode;
    current->prev = newNode;
    ++size;
}

template<typename T>
inline bool DList<T>::InsertAfter(const T& searchVal, const T& newData)
{
    Node<T>* current = findNode(searchVal);
    if (current == nullptr) return false;

    if (current == tail) {
        AddTail(newData);
    }
    else {
        Node<T>* newNode = new Node<T>(newData, current, current->next);
        current->next->prev = newNode;
        current->next = newNode;
        ++size;
    }
    return true;
}

template<typename T>
inline void DList<T>::removeHead()
{
    if (isEmpty())
        return;
    auto tmp = head;
    head = head->next;
    delete tmp;
    if (isEmpty())
        tail = nullptr;
    else
        head->prev = nullptr;
    --size;
}

template<typename T>
inline void DList<T>::removeTail()
{
    if (isEmpty())
        return;
    if (head == tail) {
        removeHead();
        return;
    }
    auto tmp = tail;
    tail = tail->prev;
    delete tmp;
    tail->next = nullptr;
    --size;
}

template<typename T>
inline void DList<T>::DeleteAll()
{
    while (!isEmpty()) {
        removeHead();
    }
}

template<typename T>
void DList<T>::print() const
{
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    auto tmp = head;
    cout << "List: ";
    while (tmp != nullptr) {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    cout << endl;
}

template<typename T>
void DList<T>::printR() const
{
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    auto tmp = tail;
    cout << "Reverse: ";
    while (tmp != nullptr) {
        cout << tmp->data << "\t";
        tmp = tmp->prev;
    }
    cout << endl;
}

template<typename T>
inline bool DList<T>::removeByData(const T& data)
{
    auto find = findNode(data);
    if (find == nullptr)
        return false;
    if (find == head)
    {
        removeHead();
        return true;
    }
    if (find == tail)
    {
        removeTail();
        return true;
    }

    auto left = find->prev;
    auto right = find->next;

    left->next = right;
    right->prev = left;

    delete find;
    --size;
    return true;
}

template<typename T>
inline size_t DList<T>::Replace(const T& oldVal, const T& newVal)
{
    size_t count = 0;
    Node<T>* tmp = head;
    while (tmp != nullptr) {
        if (tmp->data == oldVal) {
            tmp->data = newVal;
            count++;
        }
        tmp = tmp->next;
    }
    return count;
}

template<typename T>
inline void DList<T>::Reverse()
{
    if (isEmpty() || head == tail) return;

    Node<T>* current = head;
    Node<T>* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        tail = head;
        head = temp->prev;
    }
}

template<typename T>
inline Node<T>* DList<T>::findNode(const T& data)
{
    auto tmp = head;
    while (tmp != nullptr && tmp->data != data)
    {
        tmp = tmp->next;
    }
    return tmp;
}

template<typename T>
inline bool DList<T>::contains(const T& data) const
{
    Node<T>* tmp = head;
    while (tmp != nullptr) {
        if (tmp->data == data) return true;
        tmp = tmp->next;
    }
    return false;
}

template<typename T>
inline DList<T> DList<T>::operator+(const DList<T>& other) const
{
    DList<T> result;

    Node<T>* tmp = this->head;
    while (tmp != nullptr) {
        result.AddTail(tmp->data);
        tmp = tmp->next;
    }

    tmp = other.head;
    while (tmp != nullptr) {
        result.AddTail(tmp->data);
        tmp = tmp->next;
    }

    return result;
}

template<typename T>
inline DList<T> DList<T>::operator*(const DList<T>& other) const
{
    DList<T> result;
    Node<T>* tmp = this->head;

    while (tmp != nullptr) {
        if (other.contains(tmp->data) && !result.contains(tmp->data)) {
            result.AddTail(tmp->data);
        }
        tmp = tmp->next;
    }

    return result;
}