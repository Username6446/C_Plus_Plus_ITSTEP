#include <iostream>
#include "QueuePr.h"

using namespace std;

int main()
{
	QueuePr<char> q;

	q.push('A', 10); 
	q.push('B', 5);  
	q.push('C', 20); 
	q.push('D', 10); 

	cout << "Current Queue: " << endl;
	q.print();


	cout << "\nPop elements:" << endl;
	while (!q.isEmpty()) {
		cout << "Pop: " << q.pop() << endl;
	}


	return 0;
}