#include "Library.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void Library::inputBookData(Book& book) {
    cout << "Enter Author: "; getline(cin, book.author);
    cout << "Enter Title:  "; getline(cin, book.name);
    cout << "Enter Year:   "; cin >> book.year;
    book.available = true;
    cin.ignore();
}

Library::Library() {
    lib = {
        Book("Orwell", "1984", 1949),
        Book("Rowling", "Harry Potter", 1997),
        Book("Tolkien", "The Hobbit", 1937),
        Book("Orwell", "Animal Farm", 1945)
    };
}

void Library::addBook() {
    cout << "\n--- Adding New Book ---\n";
    Book tmp;
    inputBookData(tmp);
    lib.push_back(tmp);
    cout << "Book added successfully!\n";
}

void Library::print() const {
    if (lib.empty()) {
        cout << "Library is empty.\n";
        return;
    }
    int index = 0;
    for (const auto& book : lib) {
        cout << "[" << index++ << "] " << book;
    }
}

void Library::searchBook(const string& author, const string& name) {
    auto it = find_if(lib.begin(), lib.end(), [&author, &name](const Book& b) {
        return b.author == author && b.name == name;
        });

    if (it != lib.end()) {
        cout << "\n[FOUND]:" << *it << endl;
    }
    else {
        cout << "\n[NOT FOUND]: Book '" << name << "' by " << author << " not found.\n";
    }
}

void Library::searchByAuthor(const string& author) {
    cout << "\n--- Books by " << author << " ---\n";
    bool found = false;
    for_each(lib.begin(), lib.end(), [&author, &found](const Book& b) {
        if (b.author == author) {
            cout << b;
            found = true;
        }
        });

    if (!found) cout << "No books found by this author.\n";
}

void Library::issueBook(const string& name) {
    auto it = find_if(lib.begin(), lib.end(), [&name](const Book& b) {
        return b.name == name;
        });

    if (it != lib.end()) {
        if (it->available) {
            it->available = false;
            cout << "You have successfully taken the book: " << name << endl;
        }
        else {
            cout << "Book is already issued to someone else.\n";
        }
    }
    else {
        cout << "Book not found.\n";
    }
}

void Library::returnBook(const string& name) {
    auto it = find_if(lib.begin(), lib.end(), [&name](const Book& b) {
        return b.name == name;
        });

    if (it != lib.end()) {
        it->available = true;
        cout << "Book returned: " << name << endl;
    }
    else {
        cout << "Book not found in our library catalog.\n";
    }
}

void Library::sortBooks() {
    lib.sort([](const Book& a, const Book& b) {
        if (a.author == b.author) {
            return a.name < b.name;
        }
        return a.author < b.author;
        });
    cout << "Library sorted by Author and Title.\n";
}

void Library::removeBookByDetails(const string& author, const string& name, size_t year) {
    size_t oldSize = lib.size();

    lib.remove_if([&](const Book& b) {
        return b.author == author && b.name == name && b.year == year;
        });

    if (lib.size() < oldSize) {
        cout << "Book removed successfully.\n";
    }
    else {
        cout << "Book to remove not found.\n";
    }
}

void Library::removeBookByIndex(int index) {
    if (index < 0 || index >= lib.size()) {
        cout << "Invalid index.\n";
        return;
    }

    auto it = lib.begin();
    advance(it, index);
    lib.erase(it);
    cout << "Book at index " << index << " removed.\n";
}

void Library::editBook(int index) {
    if (index < 0 || index >= lib.size()) {
        cout << "Invalid index.\n";
        return;
    }

    auto it = lib.begin();
    advance(it, index);

    cout << "\n--- Editing Book [" << it->name << "] ---\n";
    cout << "Enter NEW Author (current: " << it->author << "): ";
    string input; getline(cin, input);
    if (!input.empty()) it->author = input;

    cout << "Enter NEW Title (current: " << it->name << "): ";
    getline(cin, input);
    if (!input.empty()) it->name = input;

    cout << "Enter NEW Year (current: " << it->year << "): ";
    if (cin.peek() != '\n') {
        cin >> it->year;
        cin.ignore();
    }
    else {
        cin.ignore();
    }

    cout << "Book updated.\n";
}