#pragma once
#include "Contact.h"
#include <iostream>
#include <fstream>
using namespace std;

class PhoneBook {
private:
    Contact* contacts;        
    int capacity;
    int size;

    void resize() {
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;
        Contact* newContacts = new Contact[newCapacity];

        for (int i = 0; i < size; i++) {
            newContacts[i] = contacts[i];
        }

        delete[] contacts;
        contacts = newContacts;
        capacity = newCapacity;
    }

public:
    PhoneBook() : contacts(nullptr), capacity(0), size(0) {}
    ~PhoneBook() {
        delete[] contacts;
    }
    PhoneBook(const PhoneBook& other) : contacts(nullptr), capacity(0), size(0) {
        *this = other;
    }

    PhoneBook& operator=(const PhoneBook& other) {
        if (this != &other) {
            delete[] contacts;
            size = other.size;
            capacity = other.capacity;
            contacts = new Contact[capacity];
            for (int i = 0; i < size; i++) {
                contacts[i] = other.contacts[i];
            }
        }
        return *this;
    }

    void addContact(const Contact& contact);
    void removeContact(const char* name);
    void searchContact(const char* name) const;
    void showAllContacts() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);

    int getSize() const {
        return size;
    }
};

void getInput(const char* prompt, char* buffer, int size);