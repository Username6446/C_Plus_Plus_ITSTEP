#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    const int size = 4;
    int arr[size][size]{};
    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size;) {
            int num = rand() % 16 + 1;
            bool flag = true;

            for (int k = 0; k < size; k++) {
                for (int q = 0; q < size; q++) {
                    if (arr[k][q] == num) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }

            if (flag) {
                arr[i][j] = num;
                j++;
            }
        }
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[i][j] == 16) {
                arr[i][j] = 0;
            }

	int spaceI = 0, spaceJ = 0, number = 1;
	bool flag = true;
    int count = 0;

    do {
        
        system("cls");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                
                if (arr[i][j] == 0) {
					cout << " " << "\t";
                    spaceI = i;
					spaceJ = j;
                }
                else {
                    cout << arr[i][j] << "\t";
                }
            }
            cout << "\n\n";
        }

        int inp;
		cout << "Enter number to move: ";
        cin >> inp;
        

        int temp = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(arr[i][j] == inp) {
                    if ((i == spaceI && (j == spaceJ - 1 || j == spaceJ + 1)) ||
                        (j == spaceJ && (i == spaceI - 1 || i == spaceI + 1))) {
                        arr[spaceI][spaceJ] = inp;
                        arr[i][j] = 0;
                        count++;
                    }
				}
			}
        }


        bool win = true;
        int num = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == size - 1 && j == size - 1) {
                    if (arr[i][j] != 0) win = false;
                }
                else {
                    if (arr[i][j] != num) win = false;
                    num++;
                }
            }
        }
        if (win) {
            cout << "You win!\n";
            break;
        }
    } while (flag);

	cout << "Number of moves: " << count << "\n";



}
