#include "control_library.h"

void printBook(const Book& book)
{
	cout << "\t\t Title     :: " << book.name << endl;
	cout << "\t\t Author    :: " << book.author << endl;
	cout << "\t\t Publisher :: " << book.publisher << endl;
	cout << "\t\t Genre     :: " << book.genre << "\n\n";
}

void printBooks(const Book* library, const size_t& size)
{
	for (size_t i = 0; i < size; i++) {
		cout << "\n\n\t===================== Book #" << i + 1 << " =====================" << "\n\n";
		printBook(library[i]);
	}
}

void editBook(Book& book)
{
	cout << "\t\t Title     :: "; getline(cin, book.name);
	cout << "\t\t Author    :: "; getline(cin, book.author);
	cout << "\t\t Publisher :: "; getline(cin, book.publisher);
	cout << "\t\t Genre     :: "; getline(cin, book.genre);
}

int searchByAuthor(const Book* library, const size_t& size, const string& author, const int& index)
{
	for (size_t i = index; i < size; i++) {
		if (toLower(library[i].author) == toLower(author)) {
			return i;
		}
	}
	return -1;
}

int searchByName(const Book* library, const size_t& size, const string& name, const int& index)
{
	for (size_t i = index; i < size; i++) {
		if (toLower(library[i].name) == toLower(name)) {
			return i;
		}
	}
	return -1;
}

string toLower(const string& str)
{
	string copy = str;
	for (size_t i = 0; i < copy.size(); i++) {
		copy[i] = tolower(copy[i]);
	}
	return copy;
}

void sortByTitle(Book* library, const size_t& size)
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (toLower(library[j].name) > toLower(library[j + 1].name)) {
				swap(library[j], library[j + 1]);
			}
		}
	}
}

void sortByAuthor(Book* library, const size_t& size)
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (toLower(library[j].author) > toLower(library[j + 1].author)) {
				swap(library[j], library[j + 1]);
			}
		}
	}
}

void sortByPublisher(Book* library, const size_t& size)
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (toLower(library[j].publisher) > toLower(library[j + 1].publisher)) {
				swap(library[j], library[j + 1]);
			}
		}
	}
}

void addBook(Book*& library, int& size)
{
	Book new_book{};
	Book* tmp = new Book[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = library[i];
	}
	tmp[size] = new_book;
	size++;
	delete[] library;
	library = tmp;
}

void removeBook(Book*& library, int& size, const int id)
{
	Book* tmp = new Book[--size];
	for (size_t i = 0; i < size; i++)
	{
		if (i < id) {
			tmp[i] = library[i];
		}
		else {
			tmp[i] = library[i + 1];
		}
	}
	delete[] library;
	library = tmp;
}

void removeBookByCriterion_Helper(Book*& library, int& size, int criterion, const string& choice)
{
	Book* tmp = new Book[size];
	int count = 0;

	for (int i = 0; i < size; i++) {
		bool match = false;

		switch (criterion) {
		case 1: match = (toLower(library[i].name) == toLower(choice)); break;
		case 2: match = (toLower(library[i].author) == toLower(choice)); break;
		case 3: match = (toLower(library[i].publisher) == toLower(choice)); break;
		default: cout << "Invalid criterion!\n"; break;
		}

		if (!match) tmp[count++] = library[i];
	}

	cout << "Removed " << (size - count) << " book(s).\n";

	delete[] library;
	library = tmp;
	size = count;
}


void LibraryProgram(Book*& library, int& size)
{
	while (true) {
		cout << R"(
					Welcome to DataBase Library
					
	Choose the action:

	1 - Print all books	
	2 - Add new book
	3 - Edit book
	4 - Search book by author 
	5 - Search book by name 
	6 - Sort books by name 
	7 - Sort books by author 
	8 - Remove book by index
	9 - Remove book by criterion 
	0 - Exit

	Your choice :: )";

		int choice;
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1: {
			if (size == 0) cout << "Library is empty!\n";
			else printBooks(library, size);
			break;
		}

		case 2: {
			addBook(library, size);
			cout << "Enter new book details:\n";
			editBook(library[size - 1]);
			cout << "Book added!\n";
			break;
		}

		case 3: {
			cout << "Enter book name to edit :: ";
			string name;
			getline(cin, name);
			int index = searchByName(library, size, name);
			if (index != -1) {
				cout << "Editing book:\n";
				editBook(library[index]);
				cout << "Book updated!\n";
			}
			else {
				cout << "Book not found!\n";
			}
			break;
		}

		case 4: {
			cout << "Enter author name to search :: ";
			string author;
			getline(cin, author);
			bool found = false;
			for (int i = 0; i < size; i++) {
				if (toLower(library[i].author) == toLower(author)) {
					printBook(library[i]);
					found = true;
				}
			}
			if (!found) cout << "No books found for this author!\n";
			break;
		}

		case 5: {
			cout << "Enter book name to search :: ";
			string name;
			getline(cin, name);
			int index = searchByName(library, size, name);
			if (index != -1) {
				printBook(library[index]);
			}
			else {
				cout << "Book not found!\n";
			}
			break;
		}

		case 6: {
			sortByTitle(library, size);
			cout << "Books sorted by name!\n";
			break;
		}

		case 7: {
			sortByAuthor(library, size);
			cout << "Books sorted by author!\n";
			break;
		}

		case 8: {
			if (size == 0) {
				cout << "Library is empty!\n";
				break;
			}
			cout << "Enter index of book to remove (1-" << size << ") :: ";
			int id;
			cin >> id;
			cin.ignore();
			if (id > 0 && id <= size) {
				removeBook(library, size, id - 1);
				cout << "Book removed!\n";
			}
			else {
				cout << "Invalid index!\n";
			}
			break;
		}

		case 9: {
			removeBookByCriterion(library, size);
			break;
		}

		case 0: {
			cout << "Exiting program...\n";
			return;
		}

		default: {
			cout << "Invalid choice!\n";
			break;
		}
		}
	}
}

void removeBookByCriterion(Book*& library, int& size)
{
	cout << "Enter criterion to delete book (1 - name, 2 - author, 3 - publisher) :: ";
	int criterion;
	cin >> criterion;
	cin.ignore();

	string value;
	cout << "Enter value to delete :: ";
	getline(cin, value);

	removeBookByCriterion_Helper(library, size, criterion, value);
}

