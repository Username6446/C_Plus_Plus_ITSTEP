#include <iostream>

using namespace std;



size_t strLen(const char* str)
{
	size_t counter = 0;
	while (str[counter] != '\0')
	{ 
		counter++;
	}
	return counter;
}

int main()
{
	//Plum

	 /*char word[5];
	 word[0] = 'P';
	 word[1] = 'l';
	 word[2] = 'u';
	 word[3] = 'm';
	 word[4] = '\0';

	 cout << word << endl;*/

	 /*char word[]{'P','l','u','m','\0'};
	 cout << word << endl;*/

	//char word[20] = "Apple";
	//cout << word << endl;

	//char word_2[] = "Banana";
	//cout << "Length word {" << word << "} :: " << strLen(word) << endl;
	//cout << "Length word {" << word_2 << "} :: " << strLen(word_2) << endl;
	//cout << "Length word {" << "Hello" << "} :: " << strLen("Hello") << endl;
	//cout << "Length word {" << "" << "} :: " << strLen("") << endl;


	//cout << "\n\n =========================== strlen() ========================\n\n";
	//cout << "Length word {" << word << "} :: " << strlen(word) << endl;
	//cout << "Length word {" << word_2 << "} :: " << strlen(word_2) << endl;
	//cout << "Length word {" << "Hello" << "} :: " << strlen("Hello") << endl;
	//cout << "Length word {" << "" << "} :: " << strlen("") << endl;


	///*word = "Testttttt";*/
	//cout << "\n\n =========================== strcpy(str1, str2) ========================\n\n";
	//cout << "Before :: " << word << endl;
	//strcpy_s(word, word_2);
	//cout << "After  :: " << word << endl;
	//strcpy_s(word, "Hello World");
	//cout << "After  :: " << word << endl;
	//cout << "\n\n =========================== strcpy(*str1, str2) ========================\n\n";

	//char* str = new char[30];
	//cout << "Before :: " << str << endl;
	//strcpy_s(str, 12, "Lorem ipsum");
	//cout << "After  :: " << str << endl;

	//cout << "\n\n =========================== strncpy(str1, str2) ========================\n\n";
	//cout << "Before :: " << word << endl;
	//strncpy_s(word, "HTML,CSS,C++,JAVA", 4);
	//cout << "After  :: " << word << endl;


	//cout << "\n\n =========================== strcat(str1, str2) ========================\n\n";
	//char line[50] = "Hello World";
	//cout << "Before :: " << line << endl;
	//strcat_s(line, " I Love C++");
	//cout << "After  :: " << line << endl;

	//cout << "\n\n =========================== strcat(*str1, str2) ========================\n\n";
	//cout << "Before :: " << str << endl;
	//strcat_s(str, 20, " Dolor!!");
	//cout << "After  :: " << str << endl;

	//cout << "\n\n =========================== strncat(str1, str2) ========================\n\n";
	//cout << "Before :: " << line << endl;
	//strncat_s(line, "Yellow, Purple, Pink, Green", 10);
	//cout << "After  :: " << line << endl;


	//cout << "\n\n =========================== strcmp(str1, str2) ========================\n\n";
	//char a[] = "dew";
	//char b[] = "def";
	//cout << a << " -- " << b << " :: " << strcmp(a, b) << endl;
	//cout << a << " -- " << b << " :: " << strncmp(a, b, 2) << endl;


	//char letters[] = "fdrHGTY !) 7364";
	//cout << "\n\n =========================== isalpha(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (bool)isalpha(letters[i]) << endl;
	//}
	//cout << "\n\n =========================== isalnum(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (bool)isalnum(letters[i]) << endl;
	//}

	//cout << "\n\n =========================== isdigit(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (bool)isdigit(letters[i]) << endl;
	//}

	//cout << "\n\n =========================== isspace(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (bool)isspace(letters[i]) << endl;
	//}

	//cout << "\n\n =========================== ispunct(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (bool)ispunct(letters[i]) << endl;
	//}

	//cout << "\n\n =========================== islower(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (bool)islower(letters[i]) << endl;
	//}

	//cout << "\n\n =========================== isupper(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (bool)isupper(letters[i]) << endl;
	//}


	//cout << "\n\n =========================== tolower(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (char)tolower(letters[i]) << endl;
	//}

	//cout << "\n\n =========================== toupper(letter) ========================\n\n";
	//for (size_t i = 0; i < strlen(letters); i++)
	//{
	//	cout << "\t " << letters[i] << " --> " << boolalpha << (char)toupper(letters[i]) << endl;
	//}



	//char username[100];
	//char email[30];
	//int age;

	//cout << "Enter name, surname --> ";
	//cin.getline(username, 100);
	////cin >> username;

	//cout << "Enter age :: ";
	//cin >> age;

	//cin.ignore();

	//cout << "Enter email :: ";
	//cin.getline(email, 30);
	////cin >> email;

	//cout << "User name :: " << username << endl;
	//cout << "Email :: " << email << endl;


///////////////////////////   ex 1

	char ex1[100] = "1qwerw r23 r43rf ewq fsdaf 3 er fre gasd gds g";
	cout << "\n\n\n\n\n\nEx1\n" << ex1 << endl;
	int count = 0;
	while (ex1[count] != '\0') {
		if ((bool)isspace(ex1[count])) {
			ex1[count] = '\t';
		}
		count++;
	}
	cout << ex1;
	


///////////////////////////   ex 2 
	
	char ex2[100] = "1qwerw r23 r43rf ewq fsdaf 3 er fre gasd gds g";
	cout << "\n\n\n\n\n\nEx2\n" << ex2 << endl;

	count = 0;
	int n = 0;
	while (ex1[count] != '\0') {
		if ((bool)isalpha(ex1[count]) or (bool)isalpha(ex1[count])) {
			n++;
		}
		count++;
	}

	cout << "Count :: " << n;

///////////////////////////   ex 3

	char ex3[100] = "1qwerw r23 r43rf ewq fsdaf 3 er fre gasd gds g";
	cout << "\n\n\n\n\n\nEx3\n" << ex3 << endl;
	count = 0;
	int n1 = 0;
	bool flag = false;
	while (ex1[count] != '\0') {
		if ((bool)isspace(ex1[count])) {
			flag = false;
		}
		else if (!flag) {
			n1++;
			flag = true;
		}
		count++;
	}
	cout << "Count :: " << n1;


///////////////////////////   ex 4

	char ex4[100] = "qwerrewq";
	cout << "\n\n\n\n\n\nEx4\n" << ex4 << endl;
	int left = 0;
	int right = strlen(ex4) - 1;
	bool result = true;
	while (left < right) {
		if (ex4[left] != ex4[right]) {
			result = false;
			break;
		}
		left++;
		right--;
	}
	
	if (result) {
		cout << "Palindrom";
	}
	else {
		cout << "Not Palindrom";
	}

///////////////////////////   ex 5
///////////////////////////   ex 6

}