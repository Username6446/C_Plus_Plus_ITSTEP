#include "PhoneBook.h"
#include <iostream>
#include <cstring>
using namespace std;

void PhoneBook::addContact(const Contact& contact) {
    if (size >= capacity) {
        resize();
    }
    contacts[size] = contact;
    size++;
    cout << "Contact added successfully!" << endl;
}

void PhoneBook::removeContact(const char* name) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (contacts[i].compareName(name)) {
            for (int j = i; j < size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            size--;
            found = true;
            i--;
        }
    }

    if (found) {
        cout << "Contact deleted successfully!" << endl;
    }
    else {
        cout << "Contact not found!" << endl;
    }
}

void PhoneBook::searchContact(const char* name) const {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (contacts[i].compareName(name)) {
            contacts[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "Contact not found!" << endl;
    }
}

void PhoneBook::showAllContacts() const {
    if (size == 0) {
        cout << "Phone book is empty!" << endl;
        return;
    }

    cout << "\n=== ALL CONTACTS ===" << endl;
    for (int i = 0; i < size; i++) {
        contacts[i].display();
    }
}

void PhoneBook::saveToFile(const char* filename) const {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    file << size << endl;
    for (int i = 0; i < size; i++) {
        contacts[i].saveToFile(file);
    }

    file.close();
    cout << "Data saved to file: " << filename << endl;
}

void PhoneBook::loadFromFile(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    int count;
    file >> count;
    file.ignore();

    delete[] contacts;
    contacts = new Contact[count];
    capacity = count;
    size = count;

    for (int i = 0; i < count; i++) {
        contacts[i].loadFromFile(file);
    }

    file.close();
    cout << "Data loaded from file: " << filename << endl;
}

void getInput(const char* prompt, char* buffer, int size) {
    cout << prompt;
    cin.getline(buffer, size);
}