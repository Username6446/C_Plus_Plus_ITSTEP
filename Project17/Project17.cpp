#include "control_library.h"

int main()
{
	int size = 10;
	Book* library = new Book[size]
	{
	   {"Iron Flame","Rebecca Yarros","Entangled: Red Tower Books","Fantasy"},

	   {"The Ever King","LJ Andrews","Victorious","Fantasy"},

	   {"Harry Potter and the Philosopher's Stone","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},

	   {"Harry Potter and the Chamber of Secrets","J.K. rowling","Pottermore Publishing","Children's Fantasy"},

	   {"Harry Potter and the Prisoner of Azkaban","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},

	   {"Harry Potter and the Order of the Phoenix","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},

	   {"Harry Potter and the Half-Blood Prince","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},

	   {"Crown of Blood and Ruin","LJ Andrews","Victorious","Dark Fantasy Horror"},

	   {"Battlefield Reclaimer","David North","High Peak Publishing","Fiction"},

	   {"Swords of Empire","Robert Ryan","Trotting Fox Press","Fantasy"},

	};

	//cout << "\n\n Test Print Book " << endl;

	//printBook(library[0]);

	//cout << "\n\n Test Print All Books " << endl;

	//printBooks(library, size);

	///*cout << "\n\n Test У EditBook All Books " << endl;

	//editBook(library[0]);

	//cout << "\n\n Test editBook All Books " << endl;

	//printBook(library[0]);*/

	//cout << toLower("TEST") << endl;
	//int ind = searchByAuthor(library, size, "J.K. Rowling");
	//cout << "ID :: " << ind << endl;
	//while (ind != -1) {
	//	cout << endl;
	//	printBook(library[ind]);
	//	ind = searchByAuthor(library, size, "J.K. Rowling", ind + 1);
	//}

	//sortByTitle(library, size);
	//printBooks(library, size);

	//cout << "Add new book" << endl;
	//addBook(library, size);
	//printBooks(library, size);


	//cout << "Remove book" << endl;
	//removeBook(library, size, 0);
	//printBooks(library, size);
	LibraryProgram(library, size);
}

