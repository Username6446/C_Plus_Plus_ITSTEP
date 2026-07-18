#pragma once
#include <list>
#include <string>
#include "Book.h"

using namespace std;

class Library
{
private:
    list<Book> lib;

    void inputBookData(Book& book);

public:
    Library();

    void addBook();
    void print() const;
    void searchBook(const string& author, const string& name);
    void searchByAuthor(const string& author);
    void issueBook(const string& name);
    void returnBook(const string& name);
    void sortBooks();
    void removeBookByDetails(const string& author, const string& name, size_t year);
    void removeBookByIndex(int index);
    void editBook(int index);
};