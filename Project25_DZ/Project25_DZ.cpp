#include <iostream>
#include "String.h"
int main()
{
	cout << String::getCount() << endl;

	String s1;
	String s2("Hello");
	String s3(s2);
	String s4(50);

	s2.output();
	s3.output();
	cout << String::getCount() << endl;

	s1.input();
	s1.output();

	String sConcat = s2.concat(s1);
	sConcat.output();

	String word1("programming");
	String word2("language");

	word1.output();
	word2.output();

	String common = word1.intersection(word2);
	common.output();

	String a("Apple");
	String b("Banana");

	cout << String::cmp(a, b) << endl;
	cout << String::cmp(b, a) << endl;
	cout << String::cmp(a, a) << endl;

	const int N = 5;
	String arr[N];

	arr[0] = "Zebra";
	arr[1] = "Apple";
	arr[2] = "Orange";
	arr[3] = "Banana";
	arr[4] = "Melon";

	for (int i = 0; i < N; i++) {
		arr[i].output();
	}

	String::sort(arr, N);

	cout << endl;
	for (int i = 0; i < N; i++) {
		arr[i].output();
	}

	cout << String::getCount() << endl;

	return 0;
}
