#include <iostream>
using namespace std;

enum colors {
	EXIT, RED = 1, GREEN, YELLOW, AQUA, PURPLE
};

enum products{
	EX, EGGS, BREAD, WATER, OIL
};


int main()
{
	/*
		while(){}
		do{}while()
		for(start, end, step){}
	*/


	/*  int i = 0;
	  while (i < 10)
	  {
		  cout << ++i << "\t";
	  }
	  cout << endl;

	  while (true)
	  {

	  }*/

	  /*int res;
	  do
	  {
		  cout << "2 + 2 = ";
		  cin >> res;
	  } while (res != 4);

	  cout << "Congratulation" << endl;*/
	  /*size_t i = 0;
	  for (;;)
	  {
		  i++;
		  cout << i << "\t";
		  if (i == 10)
			  break;
	  }
	  cout << endl;
	  cout << i << endl;*/

	  /*for (size_t i = 1; i <= 20; i++)
	  {
		  if (i % 3 == 0)
			  continue;

		  cout << i << "\t";
	  }
	  cout << endl;*/

	  /*for (int i = 0, q = 9; i < 10 and q >= 0; i++, q--)
	  {
		  cout << i << "\t" << q << endl;
	  }*/

	/*int choice;
	do
	{
		system("cls");
		cout << R"(
			1 - Red;
			2 - Green;
			3 - Yellow;
			4 - Aqua;
			5 - Purple;
			0 - Exit
			Enter choice :: )";
		cin >> choice;
		switch (choice)
		{
		case colors::RED:
			system("color 04"); break;
		case colors::GREEN:
			system("color 02"); break;
		case colors::YELLOW:
			system("color 06"); break;
		case colors::AQUA:
			system("color 03"); break;
		case colors::PURPLE:
			system("color 05"); break;
		}
	} while (choice != colors::EXIT);*/

 //   //Ex 1
	//int num;
	//cout << "Enter num :: ";
	//cin >> num;

	//for (int i = 0; i <= num; i++) {
	//	cout << i << endl;
	//}

 //   //Ex 2

	//int num1, num2;
	//cout << "Enter num 1:: ";
	//cin >> num1;
	//cout << "Enter num 2:: ";
	//cin >> num2;

	//if (num1 > num2) {
	//	int temp = num1;
	//	num1 = num2;
	//	num2 = temp;
	//}
	//
	//cout << "Even" << endl;
	//for (int i = num1; i < num2; i++) {
	//	if (i % 2 == 0){
	//		cout << i << endl;
	//	}
	//}
	//cout << "Odd" << endl;
	//for (int i = num1; i < num2; i++) {
	//	if (i % 2 == 1){
	//		cout << i << endl;
	//	}
	//}
	//cout << "7-th" << endl;
	//for (int i = num1; i < num2; i++) {
	//	if (i % 7 == 0){
	//		cout << i << endl;
	//	}
	//}

	////Ex3

	////int num1, num2;
	//cout << "Enter num 1:: ";
	//cin >> num1;
	//cout << "Enter num 2:: ";
	//cin >> num2;

	//if (num1 > num2) {
	//	int temp = num1;
	//	num1 = num2;
	//	num2 = temp;
	//}

	//int sum = 0;
	//for (int i = num1; i <= num2; i++) {
	//	sum += i;
	//}
	//cout << "Sum :: " << sum << endl;
	//// Ex 4
	//
	//sum= 0;
	//int number;
	//do {
	//	cout << "Enter number ::";
	//	cin >> number;
	//	sum += number;
	//} while (number != 0);
	//cout << "Sum :: " << sum << endl;

	//// Ex 5

	int num1;
	int num2;
	int number;

	cout << "Enter num start:: ";
	cin >> num1;
	cout << "Enter num end:: ";
	cin >> num2;
	do {
		cout << "Enter number:: ";
		cin >> number;
	} while (number > num2 || number < num1);
	
	//// Ex 5
	int Sum = 0;
	while (true) {
		int sum = 0;
		int cost = 0;
		string name = "";
		int choice;
		do {
			cout << R"(
			1 - Eggs cost = 1$;
			2 - Bread cost = 2$;
			3 - Water cost = 3$;
			4 - Oil cost = 4$;
			0 - Exit
			Enter choice :: )";
			cin >> choice;
			switch (choice)
			{
			case products::EGGS:
				cost = 1;
				name = "Eggs";
				break;
			case products::BREAD:
				cost = 2;
				name = "Bread";
				break;
			case products::WATER:
				cost = 3;
				name = "Water";
				break;
			case products::OIL:
				cost = 4;
				name = "Oil";
				break;
			case products::EX:
				continue;
			default:
				cout << "Invalid choice!" << endl;
				continue;
			}
			int nums;
			cout << "\n\t\t\tEnter nums of " << name << ":: ";
			cin >> nums;
			sum += cost * nums;
		} while (choice != products::EX);

		cout << "To pay :: " << sum << "$" << endl;
		Sum += sum;

		int c;
		cout << "One more customer?\n 1 - yes, 0 - no :: ";
		cin >> c;
		if (c==0) {
			break;
		}
	}
	
	cout << "All sum = " << Sum;

}