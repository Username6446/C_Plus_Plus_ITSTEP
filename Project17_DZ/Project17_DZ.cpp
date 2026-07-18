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

	LibraryProgram(library, size);
}

