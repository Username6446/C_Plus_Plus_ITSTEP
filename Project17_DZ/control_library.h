#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::swap;


struct Book {
	string name;
	string author;
	string publisher;
	string genre;
};

void printBook(const Book& book);
void printBooks(const Book* library, const size_t& size);

void editBook(Book& library);

int searchByAuthor(const Book* library, const size_t& size, const string& author, const int& index = 0);
int searchByName(const Book* library, const size_t& size, const string& name, const int& index = 0);

string toLower(const string& str);

void sortByTitle(Book* library, const size_t& size);
void sortByAuthor(Book* library, const size_t& size);
void sortByPublisher(Book* library, const size_t& size);

void addBook(Book*& library, int& size);

void removeBook(Book*& library, int& size, const int id);
void removeBookByCriterion(Book*& library, int& size);
void removeBookByCriterion_Helper(Book*& library, int& size, int criterion, const string& choice);

void LibraryProgram(Book*& library, int& size);